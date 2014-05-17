/*
** display_args.c for  in /home/otoshigami/Workspace/Epitech/git/AUSP_strace
**
** Made by otoshigami
** Login   <otoshigami@epitech.net>
**
** Started on  Sat May 17 18:58:12 2014 otoshigami
** Last update Sat May 17 18:58:13 2014 otoshigami
*/

#include <stdio.h>
#include <sys/user.h>

#include "syscallent.h"

static int	get_argc(struct user_regs_struct* regs)
{
  if (regs->rax >= 314)
    return (0);
  return (syscallent[regs->rax].argsnumber);
}

static void	get_argv(struct user_regs_struct* regs, long* argv)
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
  printf(")");
}
