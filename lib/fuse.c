/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 09/11/2021 12:48:54
**
** - Fuse -
**
** *****************************************************************************
*/

#include "std_archive.h"

char	*fuse(const char	*src,
              const char	*merge,
              long		size1,
              long		size2)
{
  int	i;
  char	*fuse;

  i = 0;
  fuse = malloc(size1 + size2 + 1);
  while (i < size1)
    {
      fuse[i] = src[i];
      ++i;
    }
  while (i < size1 + size2)
    {
      fuse[i] = merge[i - size1];
      ++i;
    }
  fuse[i] = 0;
  return (fuse);
}

