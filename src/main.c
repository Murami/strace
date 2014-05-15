#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/reg.h>
#include <sys/user.h>

#include "params.h"
#include "syscallent.h"

long	peek_data(int pid, void* addr)
{
  long	value;

  if ((value = ptrace(PTRACE_PEEKDATA, pid, addr, 0)) == -1)
    {
      perror("error: can't get data");
      return (-1);
    }
  return (value);
}

int	get_regs(int pid, struct user_regs_struct* regs)
{
  if (ptrace(PTRACE_GETREGS, pid, 0, regs) == -1)
    {
      perror("error: can't get registers");
      return (-1);
    }
  return (0);
}

int	is_syscall(int pid)
{
  struct user_regs_struct	regs;
  long				instr;

  if (get_regs(pid, &regs))
    return (0);
  if ((instr = peek_data(pid, (void*)regs.rip)) == -1)
    return (0);
  if ((instr & 0x0000ffff) == 0x050f ||
      (instr & 0x0000ffff) == 0x340f ||
      (instr & 0x0000ffff) == 0x80cd)
    return (1);
  return (0);
}

int	launch_son(char** argv)
{
  int	pid;

  if ((pid = fork()) == -1)
    return (-1);

  if (!pid)
    {
      ptrace(PTRACE_TRACEME, 0, 0, 0);
      execvp(argv[0], argv + 1);
      exit(EXIT_FAILURE);
    }
  return (pid);
}

int	trace_infos(int pid)
{
  struct user_regs_struct	regs;

  if (get_regs(pid, &regs) == -1)
    return (-1);
  if (regs.rax >= 314)
    printf("unknonw syscalls\n");
  else
    printf("%s\n", syscallent[regs.rax].callname);
  return (0);
}

int	next_step(int pid)
{
  if (ptrace(PTRACE_SINGLESTEP, pid, 0, NULL) == -1)
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
      waitpid(pid, &status, 0);

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

      if (is_syscall(pid))
	{
	  if (trace_infos(pid) == -1)
	    return (-1);
	}

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

int	trace(int pid, char** argv)
{
  if (pid != -1)
    return (trace_pid(pid, 0));
  else
    {
      if ((pid = launch_son(argv)) == -1)
	return (-1);
      return (trace_pid(pid, 1));
    }
  return (0);
}

int	main()
{
  params_t	params;
  char*		av[2] =
    {
      "ls",
      "ls"
    };

  params.pid = -1;
  params.argv = av;
  if (trace(params.pid, params.argv) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
