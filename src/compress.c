/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@csr-pi02.ecole-89.com>
**
** compress - 2022
**
** *****************************************************************************
*/

#include	"std_archive.h"

static void	std_free_compression_element(t_file	*file,
					     char	*str,
					     int	fd)
{
  free(file->name);
  free(file);
  free(str);
  close(fd);
}

int             std_compress(int			ar_fd,
                             t_queue			**que)
{
  t_file        *file;
  t_queue       *nque;
  int           fd;
  char          *str;

  nque = NULL;
  file = (t_file*) std_queue_top(que);
  while (file != NULL)
    {
      std_queue_push(&nque, std_queue_pop(que));
      std_write_header(ar_fd, que, file);
      file = (t_file*) std_queue_top(que);
    }
  write(ar_fd, "\n", sizeof(char));
  while (nque != NULL)
    {
      file = std_queue_pop(&nque);
      if ((str = malloc(file->size)) == NULL)
        return (-1);
      fd = open(file->name, O_RDONLY, 0666);
      read(fd, str, file->size);
      write(ar_fd, str, file->size);
      std_free_compression_element(file, str, fd);
    }
  return (0);
}

