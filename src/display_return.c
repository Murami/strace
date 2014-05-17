/*
** display_return.c for  in /home/otoshigami/Workspace/Epitech/git/AUSP_strace
**
** Made by otoshigami
** Login   <otoshigami@epitech.net>
**
** Started on  Sat May 17 18:58:16 2014 otoshigami
** Last update Sat May 17 18:58:17 2014 otoshigami
*/

#include <sys/ptrace.h>
#include <sys/user.h>
#include <stdio.h>
#include "strace.h"

void	display_return(int pid)
{
  struct user_regs_struct	regs;

  if (ptrace(PTRACE_GETREGS, pid, 0, &regs) == -1)
    printf(" = ???\n");
  else
    printf(" = %lld\n", (long long int)regs.rax);
}
