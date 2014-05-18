/*
** main.c for  in /home/otoshigami/Workspace/Epitech/git/AUSP_strace
**
** Made by otoshigami
** Login   <otoshigami@epitech.net>
**
** Started on  Sat May 17 18:57:55 2014 otoshigami
** Last update Sun May 18 13:40:53 2014 pinon
*/

#include <stdio.h>
#include <stdlib.h>
#include "strace.h"

void	usage()
{
  printf("usage : ./strace [cmd | -p pid]\n");
}

int		main(int argc, char **argv)
{
  params_t	params;

  if (parser(&params, argc -1, argv + 1) == 0)
    usage();
  else if (trace(params.pid, params.argv) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
