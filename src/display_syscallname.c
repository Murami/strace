/*
** display_syscallname.c for  in /home/otoshigami/Workspace/Epitech/git/AUSP_strace
**
** Made by otoshigami
** Login   <otoshigami@epitech.net>
**
** Started on  Sat May 17 18:58:00 2014 otoshigami
** Last update Sat May 17 18:58:01 2014 otoshigami
*/

#include <stdio.h>
#include <sys/user.h>
#include "syscallent.h"

void	display_syscallname(struct user_regs_struct* regs)
{
  if (regs->rax >= 314)
    printf("???");
  else
    printf("%s", syscallent[regs->rax].callname);
}
