#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/reg.h>
#include <sys/user.h>
#include <errno.h>
#include <limits.h>

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
      execvp(argv[0], argv);
      exit(EXIT_FAILURE);
    }
  return (pid);
}

void	display_syscallname(struct user_regs_struct* regs)
{
  if (regs->rax >= 314)
    printf("???");
  else
    printf("%s", syscallent[regs->rax].callname);
}

int	get_argc(struct user_regs_struct* regs)
{
  if (regs->rax >= 314)
    return (0);
  return (syscallent[regs->rax].argsnumber);
}

void	get_argv(struct user_regs_struct* regs, long* argv)
{
  argv[0] = regs->rdi;
  argv[1] = regs->rsi;
  argv[2] = regs->rdx;
  argv[3] = regs->rcx;
  argv[4] = regs->r8;
  argv[5] = regs->r9;
}

void	display_args(struct user_regs_struct* regs)
{
  int				i;
  int				argc;
  long				argv[6];

  i = 0;
  argc = get_argc(regs);
  get_argv(regs, argv);
  printf("(");
  while (i < argc)
    {
      if (i != 0)
	printf(", ");
      printf("%ld", argv[i]);
      i++;
    }
  printf(")\n");
}

int	trace_infos(int pid)
{
  struct user_regs_struct	regs;

  if (get_regs(pid, &regs) == -1)
    return (-1);
  display_syscallname(&regs);
  display_args(&regs);
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

void	parser_ex(params_t *data, char **argv)
{
  char	*token;
  char	*save;
  int	i;

  save = NULL;
  i = 0;
  token = strtok_r(argv[0], " ", &save);
  data->argv = malloc(sizeof(char*));
  while (token != NULL)
    {
      data->argv = realloc(data->argv, (i + 1) * sizeof(char *));
      data->argv[i] = token;
      token = strtok_r(NULL, " ", &save);
      i++;
    }
  data->argv[i] = NULL;
}

int	parser(params_t *data, int argc, char **argv)
{
  char	*ptr;

  data->pid = -1;
  if (argc == 1)
    {
      parser_ex(data, argv);
      return (1);
    }
  else if (argc == 2)
    {
      if (strcmp(argv[0], "-p") == 0)
	{
	  data->pid = strtol(argv[1], &ptr, 10);
	  if (errno == ERANGE || errno == EINVAL || data->pid == 0)
	    {
	      return (0);
	    }
	  return (1);
	}
      else
	return (0);
    }
  else
    return (0);
}

void	usage()
{
  printf("usage\n");
}

int	main(int argc, char **argv)
{
  params_t	params;

  if (parser(&params, argc -1, argv + 1) == 0)
    usage();
  else if (trace(params.pid, params.argv) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
