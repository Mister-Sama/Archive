/*
** *****************************************************************************
** lenny.vigeon
** lenny.vigeon <lenny.vigeon-station>
**
** strdup.c - 2022
**
** *****************************************************************************
*/

#include "std_archive.h"

char	*std_strdup(char	*s)
{
  int	i;
  char	*str;

  i = 0;
  if ((str = malloc(std_strlen(s) + 1)) == NULL)
		return (NULL);
  while (s[i] != 0)
  {
    str[i] = s[i];
    ++i;
  }
  str[i] = 0;
  return (str);
}

