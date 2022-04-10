/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@csr-pi02.ecole-89.com>
**
** init_parameter - 2022
**
** *****************************************************************************
*/

#include	"std_archive.h"

t_queue         *std_init_parameter(int         argc,
                                    char        *argv[])
{
  int           i;
  t_queue       *que;
  t_file        *file;

  i = 2;
  que = NULL;
  while (i < argc)
    {
      file = malloc(sizeof(t_file));
      if (file == NULL)
        return (NULL);
      file->name = std_strdup(argv[i]);
      file->size = std_get_file_size(argv[i]);
      std_queue_push(&que, file);
      i = i + 1;
    }
  return (que);
}
