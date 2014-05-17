/*
** is_syscall.c for  in /home/otoshigami/Workspace/Epitech/git/AUSP_strace
**
** Made by otoshigami
** Login   <otoshigami@epitech.net>
**
** Started on  Sat May 17 18:58:20 2014 otoshigami
** Last update Sat May 17 18:58:21 2014 otoshigami
*/

#include <sys/ptrace.h>
#include <sys/user.h>

int	is_syscall(int pid)
{
  struct user_regs_struct	regs;
  long				instr;

  if (ptrace(PTRACE_GETREGS, pid, 0, &regs) == -1)
    return (0);
  if ((instr = ptrace(PTRACE_PEEKDATA, pid, (void*)regs.rip), 0) == -1)
    return (0);
  if ((instr & 0x0000ffff) == 0x050f ||
      (instr & 0x0000ffff) == 0x340f ||
      (instr & 0x0000ffff) == 0x80cd)
    return (1);
  return (0);
}
