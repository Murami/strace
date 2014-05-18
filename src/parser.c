/*
** parser.c for  in /home/otoshigami/Workspace/Epitech/git/AUSP_strace
**
** Made by otoshigami
** Login   <otoshigami@epitech.net>
**
** Started on  Sat May 17 18:58:24 2014 otoshigami
** Last update Sun May 18 13:38:17 2014 pinon
*/

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "strace.h"

int	parser(params_t *data, int argc, char **argv)
{
  char	*ptr;

  if (argc < 1)
    return (0);
  data->pid = -1;
  if (strcmp(argv[0], "-p") == 0)
    {
      if (argc < 2)
	return (0);
      else
	{
	  data->pid = strtol(argv[1], &ptr, 10);
	  if (errno == ERANGE || errno == EINVAL || data->pid == 0)
	    return (0);
	  return (1);
	}
    }
  else
    data->argv = argv;
  return (1);
}
