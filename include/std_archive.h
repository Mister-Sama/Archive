/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@csr-pi03.ecole-89.com>
**
** archive - 2022
**
** *****************************************************************************
*/

#ifndef		__ARCHIVE_H__
#define		__ARCHIVE_H__

#include	<stdbool.h>
#include	<stddef.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	<sys/stat.h>

typedef struct	u_file
{
  char	*name;
  size_t	size;
}		t_file;

#include "queue.h"
#include "lib.h"

void	*write_error(int	fd,
		     char	*text,
		     void	*return_value,
		     bool	write_red);

bool		std_decompression(char	*argv[]);

size_t          std_get_file_size(const char    *file);

t_queue         *std_init_parameter(int         argc,
                                    char        *argv[]);

void            std_write_header(int            ar_fd,
                                 t_queue        **que,
                                 t_file         *file);

int             std_compress(int		ar_fd,
                             t_queue		**que);

int             std_file_test(t_queue		**que);

int		std_print_base10(int		fd,
				 int		nbr);

int		std_compression(int	argc,
				char	*argv[]);

#endif