#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/reg.h>

#include "params.h"

int	launch_son(char* cmd)
{
  int	pid;

  if ((pid = fork()) == -1)
    return (-1);

  if (!pid)
    {
      if (ptrace(PTRACE_TRACEME) == -1)
	{
	  perror("error: can't make child a tracee");
	  return (-1);
	}
      execlp("sh", "sh", "-c", cmd, NULL);
      fprintf(stderr, "fatal error: exec failed\n");
      exit(EXIT_FAILURE);
    }
  return (pid);
}

int	trace_infos(int pid)
{
  long int	reg_a;

  if ((reg_a = ptrace(PTRACE_PEEKUSER, pid,  8 * ORIG_RAX, NULL)) == -1)
    {
      perror("error: can't get rax register");
      return (-1);
    }
  printf("%ld\n", reg_a);
  return (0);
}

int	trace_pid(int pid, int is_son)
{
  int	status;

  status = 1407;
  if (!is_son)
    if (ptrace(PTRACE_ATTACH, pid) == -1)
      {
	perror("error: can't attach process");
	return (-1);
      }
  while (WIFSTOPPED(status))
    {
      waitpid(pid, &status, __WALL);
      if (!WIFEXITED(status))
	{
	  if (trace_infos(pid) == -1)
	    return (-1);
	  if (ptrace(PTRACE_SYSCALL, pid, 1, NULL) == -1)
	    {
	      perror("error: can't trace process");
	      return (-1);
	    }
	}
      else
	ptrace(PTRACE_CONT, pid, 1, NULL);
    }
  return (0);
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
