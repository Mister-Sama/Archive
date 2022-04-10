/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@csr-pi02.ecole-89.com>
**
** get_file_size - 2022
**
** *****************************************************************************
*/

#include	"std_archive.h"

size_t          std_get_file_size(const char    *file)
{
  int           fd;
  size_t        size;
  char          str[8192];
  size_t        size_read;

  if (access(file, W_OK | R_OK) == -1)
    chmod(file, O_RDWR);
  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (0);
  size = 0;
  size_read = read(fd, str, 8192);
  while (size_read == 8192)
    {
      size = size + size_read;
      size_read = read(fd, str, 8192);
    }
  size = size + size_read;
  close(fd);
  return (size);
}
