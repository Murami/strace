#include <sys/ptrace.h>
#include <sys/user.h>
#include "strace.h"

void	display_call(int pid)
{
  struct user_regs_struct	regs;

  if (ptrace(PTRACE_GETREGS, pid, 0, &regs) == -1)
    return;
  display_syscallname(&regs);
  display_args(&regs);
}
