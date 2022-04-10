/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 10/11/2021 13:21:44
**
** - Read_Content -
**
** ALL DEPENDENCIES IN
**
** *****************************************************************************
*/

#include <unistd.h>
#include <stdlib.h>
#include "std_archive.h"

typedef struct s_read_content_cache
{
  char		*content;
  char		*temp;
  char		*get;
  ssize_t		bytes;
  int		k;
}               t_read_content_cache;

static long	rc_slen(const char	*s)
{
    long	i;

    i = 0;
    while (s[i] != 0)
        ++i;
    return (i);
}

static char	*rc_fuse(const char	*src,
			 const char	*merge,
			 long		size1,
			 long		size2)
{
  int		i;
  char		*fuse;

  i = 0;
  (fuse = malloc(size1 + size2 + 1));
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

char		*read_content(int	fd,
                              long	size,
                              char	parser)
{
  t_read_content_cache c;

  c.bytes = 1;
  c.content = std_strdup("");
  size = (size <= 0) ? 1 : size;
  if ((c.get = malloc(size)) == NULL)
    return (NULL);
  while (c.content != NULL && c.bytes > 0)
  {
    c.bytes = read(fd, c.get, size);
    c.k = 0;
    while (c.k < c.bytes && c.get[c.k] != parser)
      c.k++;
    if (c.k < c.bytes && c.get[c.k] == parser)
	    c.bytes = 0;
    c.temp = c.content;
    c.content = rc_fuse(c.temp, c.get, rc_slen(c.temp), c.k);
    free(c.temp);
  }
  free(c.get);
  return (c.content);
}

