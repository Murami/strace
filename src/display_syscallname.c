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
