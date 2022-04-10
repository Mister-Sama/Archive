/*
** Lenny Vigeon Linnchoeuh
** lenny.vigeon <lenny.vigeon@ecole-89.com>
**
** Atoi - 2021
**
** DESCRIPTION
** Takes an ASCII number and return it as an integer.
** In case the str don't start by a number or a '-' it returns 0.
*/

#include "std_archive.h"

static int	std_is_number(char	nbr)
{
  return (nbr >= '0' && nbr <= '9');
}

int		std_atoi(const char	*str)
{
  int		result;
  int		inverser;
  int		count;

  inverser = -1;
  count = -inverser;
  result = 0;
  if (str[0] != '-')
  {
    if (std_is_number(str[0]) == 0)
	return (0);
    inverser = -inverser;
    count = 0;
  }
  while (std_is_number(str[count]) != 0)
  {
    result = result * 10 + str[count] - '0';
    count = count + 1;
  }
  return (result * inverser);
}

