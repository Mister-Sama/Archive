/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 25/01/2022 14:00:00
**
** - Main -
**
** *****************************************************************************
*/

#include "std_archive.h"

#define ARGS_ERROR "Not enough arguments.\n"

int	main(int	argc,
	     char	*argv[])
{
  int	zero;

  zero = 0;
  if (argc == 1)
    return (*((int*)write_error(1, ARGS_ERROR, &zero, 1)));
  if (argc == 2)
    std_decompression(argv);
  else
  	std_compression(argc, argv);
  return (0);
}

