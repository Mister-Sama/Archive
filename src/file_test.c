/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@csr-pi02.ecole-89.com>
**
** file_test - 2022
**
** *****************************************************************************
*/

#include "std_archive.h"

int             std_file_test(t_queue   **que)
{
  t_file        *file;
  t_queue       *nque;
  int           fd;

  nque = NULL;
  file = std_queue_pop(que);
  if (file == NULL)
    return (-1);
  while (file != NULL)
    {
      fd = open(file->name, O_RDONLY);
      if (fd != -1)
        {
          std_queue_push(&nque, file);
          close(fd);
        }
      else
        free(file);
      file = std_queue_pop(que);
    }
  *que = nque;
  return (0);
}

