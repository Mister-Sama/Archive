/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@csr-pi02.ecole-89.com>
** Ecole 89 - 21/12/2021 20:19:32
**
** - Strlen -
**
** *****************************************************************************
*/

#include "std_archive.h"

size_t	std_strlen(const char	*str)
{
  if (str[0] == '\0')
    return (0);
  return (std_strlen(&str[1]) + 1);
}

