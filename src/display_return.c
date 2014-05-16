#include <sys/ptrace.h>
#include <sys/user.h>
#include <stdio.h>
#include "strace.h"

void	display_return(int pid)
{
  struct user_regs_struct	regs;

  if (ptrace(PTRACE_PEEKUSER, pid, 0, &regs) == -1)
    printf(" = ???\n");
  else
    printf(" = %lld\n", (long long int)regs.rax);
}
