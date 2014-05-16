#ifndef STRACE_H
# define STRACE_H

#include <sys/user.h>
#include "params.h"

int	trace(int, char**);
int	parser(params_t*, int, char**);
int	is_syscall(int);
void	display_syscallname(struct user_regs_struct*);
void	display_return(int);
void	display_call(int);
void	display_args(struct user_regs_struct*);

#endif /* STRACE_H */
