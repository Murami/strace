#ifndef SYSCALLENT_H
# define SYSCALLENT_H

typedef struct	syscallentry_s
{
  int		argsnumber;
  char*		callname;
}		syscallentry_t;

/*
** 314 Syscalls informations
*/

extern syscallentry_t syscallent[];

#endif /* SYSCALLENT_H */
