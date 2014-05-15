#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/reg.h>
#include <sys/user.h>

#include "params.h"

int	launch_son(char* cmd)
{
  int	pid;

  if ((pid = fork()) == -1)
    return (-1);

  if (!pid)
    {
      ptrace(PTRACE_TRACEME);
      execlp("sh", "sh", "-c", cmd, NULL);
      exit(EXIT_FAILURE);
    }
  return (pid);
}

int	trace_infos(int pid)
{
  struct user_regs_struct	regs;

  if (ptrace(PTRACE_GETREGS, pid, 0, &regs) == -1)
    {
      perror("error: can't get registers");
      return (-1);
    }
  printf("");
  return (0);
}

int	next_step(int pid)
{
  if (ptrace(PTRACE_SYSCALL, pid, 1, NULL) == -1)
    {
      perror("error: can't trace process");
      return (-1);
    }
  return (0);
}

int	trace_loop(int pid)
{
  int	status;

  printf("=== Process ID %d ===\n", pid);
  while (1)
    {
      waitpid(pid, &status, __WALL);

      if (WIFEXITED(status))
	{
	  printf("=== Exited with status %d ===\n", WEXITSTATUS(status));
	  return (0);
	}
      else if (WIFSIGNALED(status))
	{
	  printf("=== Exited with signal %d ===\n", WTERMSIG(status));
	  return (0);
	}

      if (trace_infos(pid) == -1)
	return (-1);
      if (next_step(pid) == -1)
	return (-1);
    }
}

int	trace_pid(int pid, int is_son)
{
  if (!is_son)
    if (ptrace(PTRACE_ATTACH, pid) == -1)
      {
	perror("error: can't attach process");
	return (-1);
      }
  return (trace_loop(pid));
}

int	trace(int pid, char* cmd)
{
  if (pid != -1)
    return (trace_pid(pid, 0));
  else
    {
      if ((pid = launch_son(cmd)) == -1)
	return (-1);
      return (trace_pid(pid, 1));
    }
  return (0);
}

int	main()
{
  params_t	params;

  params.pid = -1;
  params.cmd = "ls";
  if (trace(params.pid, params.cmd) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
