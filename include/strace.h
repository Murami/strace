/*
** strace.h for  in /home/otoshigami/Workspace/Epitech/git/AUSP_strace
**
** Made by otoshigami
** Login   <otoshigami@epitech.net>
**
** Started on  Sat May 17 18:58:38 2014 otoshigami
** Last update Sat May 17 18:58:39 2014 otoshigami
*/

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
