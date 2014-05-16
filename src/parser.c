#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "strace.h"

static void	parser_ex(params_t *data, char **argv)
{
  char		*token;
  char		*save;
  int		i;

  save = NULL;
  i = 0;
  token = strtok_r(argv[0], " ", &save);
  data->argv = malloc(sizeof(char*));
  while (token != NULL)
    {
      data->argv = realloc(data->argv, (i + 1) * sizeof(char *));
      data->argv[i] = token;
      token = strtok_r(NULL, " ", &save);
      i++;
    }
  data->argv[i] = NULL;
}

int	parser(params_t *data, int argc, char **argv)
{
  char	*ptr;

  data->pid = -1;
  if (argc == 1)
    {
      parser_ex(data, argv);
      return (1);
    }
  else if (argc == 2)
    {
      if (strcmp(argv[0], "-p") == 0)
	{
	  data->pid = strtol(argv[1], &ptr, 10);
	  if (errno == ERANGE || errno == EINVAL || data->pid == 0)
	    {
	      return (0);
	    }
	  return (1);
	}
      else
	return (0);
    }
  else
    return (0);
}
