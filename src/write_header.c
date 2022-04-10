/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@csr-pi02.ecole-89.com>
**
** write_header - 2022
**
** *****************************************************************************
*/

#include	"std_archive.h"

void            std_write_header(int            ar_fd,
                                 t_queue        **que,
                                 t_file         *file)
{
  write(ar_fd, file->name, std_strlen(file->name));
  write(ar_fd, "/", sizeof(char));
  std_print_base10(ar_fd, file->size);
  (que != NULL) ? write(ar_fd, "/", sizeof(char)) : 0;
}

