/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@csr-pi03.ecole-89.com>
**
** compression - 2022
**
** *****************************************************************************
*/

#include	"std_archive.h"

int		std_compression(int	argc,
				char	*argv[])
{
  int		ar_fd;
  t_queue	*que;

  if (access(argv[1], W_OK | R_OK) == -1)
    chmod(argv[1], O_RDWR);
  ar_fd = open(argv[1], O_RDWR);
  if (ar_fd == -1)
    ar_fd = open(argv[1], O_CREAT | O_RDWR, 0666);
  que = std_init_parameter(argc, argv);
  if (que == NULL)
    {
      close(ar_fd);
      return (-1);
    }
  std_file_test(&que);
  std_compress(ar_fd, &que);
  std_queue_clear(&que);
  close(ar_fd);
  return (0);
}

