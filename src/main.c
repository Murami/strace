#include <stdio.h>
#include <stdlib.h>
#include "strace.h"

void	usage()
{
  printf("usage : ./strace [cmd | -p pid]\n");
}

int	main(int argc, char **argv)
{
  params_t	params;

  if (parser(&params, argc -1, argv + 1) == 0)
    usage();
  else if (trace(params.pid, params.argv) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
