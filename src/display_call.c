/*
** display_call.c for  in /home/otoshigami/Workspace/Epitech/git/AUSP_strace
**
** Made by otoshigami
** Login   <otoshigami@epitech.net>
**
** Started on  Sat May 17 18:58:06 2014 otoshigami
** Last update Sun May 18 13:41:04 2014 pinon
*/

#include <sys/ptrace.h>
#include <sys/user.h>
#include "strace.h"

void				display_call(int pid)
{
  struct user_regs_struct	regs;

  if (ptrace(PTRACE_GETREGS, pid, 0, &regs) == -1)
    return;
  display_syscallname(&regs);
  display_args(&regs);
}
