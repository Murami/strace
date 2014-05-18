/*
** trace.c for  in /home/otoshigami/Workspace/Epitech/git/AUSP_strace
**
** Made by otoshigami
** Login   <otoshigami@epitech.net>
**
** Started on  Sat May 17 18:57:39 2014 otoshigami
** Last update Sun May 18 13:41:40 2014 pinon
*/

#include <stdbool.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "strace.h"

static int	launch_son(char** argv)
{
  int		pid;

  if ((pid = fork()) == -1)
    return (-1);
  if (!pid)
    {
      ptrace(PTRACE_TRACEME, 0, 0, 0);
      execvp(argv[0], argv);
      exit(EXIT_FAILURE);
    }
  return (pid);
}

static int	trace_terminated(int status)
{
  if (WIFEXITED(status))
    {
      printf("=== Exited with status %d ===\n", WEXITSTATUS(status));
      return (1);
    }
  else if (WIFSIGNALED(status))
    {
      printf("=== Exited with signal %d ===\n", WTERMSIG(status));
      return (1);
    }
  return (0);
}

static int	trace_loop(int pid)
{
  int		status;
  bool		sys_call_return;

  sys_call_return = false;
  printf("=== Process ID %d ===\n", pid);
  while (1)
    {
      waitpid(pid, &status, 0);
      if (sys_call_return)
	display_return(pid);
      if (trace_terminated(status))
	return (0);
      if ((sys_call_return = is_syscall(pid)))
	display_call(pid);
      if (ptrace(PTRACE_SINGLESTEP, pid, 0, 0) == -1)
	{
	  perror("error: can't trace process");
	  return (-1);
	}
    }
}

static int	trace_pid(int pid, int is_son)
{
  if (!is_son)
    if (ptrace(PTRACE_ATTACH, pid, 0, 0) == -1)
      {
	perror("error: can't attach process");
	return (-1);
      }
  return (trace_loop(pid));
}

int		trace(int pid, char** argv)
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
