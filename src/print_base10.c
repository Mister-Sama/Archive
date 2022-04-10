/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@csr-pi02.ecole-89.com>
**
** print_base10 - 2022
**
** *****************************************************************************
*/

#include "std_archive.h"

int     std_print_base10(int    fd,
                         int    nbr)
{
  char  c;
  int   count;

  if (nbr < 0)
    {
      nbr = -nbr;
      write(1, "-", 1);
    }
  c = nbr % 10 + '0';
  count = 1;
  if (nbr > 9)
    count += std_print_base10(fd, nbr / 10);
  write(fd, &c, 1);
  return (count);
}
