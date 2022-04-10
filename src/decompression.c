/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 25/01/2022 14:00:00
**
** - Main -
**
** *****************************************************************************
*/

#include "std_archive.h"

#define ARCHIVE_FAIL "Can't open archive file.\n"

static t_file	*get_info(char		*buffer,
			  size_t	*i)
{
  t_file	*file;
  char		*temp;

  if ((file = malloc(sizeof(t_file))) == NULL)
    return (NULL);
  if ((file->name = std_strdup("")) == NULL)
    return (NULL);
  while (buffer[*i] != '/' && buffer[*i] != '\0')
    {
      temp = file->name;
      file->name = fuse(temp, &buffer[*i], std_strlen(temp), 1);
      free(temp);
      (*i)++;
    }
  *i += (buffer[*i] != '\0') ? 1 : 0;
  file->size = std_atoi(&buffer[*i]);
  while (buffer[*i] != '/' && buffer[*i] != '\0')
    (*i)++;
  *i += (buffer[*i] != '\0') ? 1 : 0;
  return (file);
}

static t_queue	*read_header(int	fd)
{
  t_queue	*queue;
  char		*buffer;
  size_t	i;

  queue = NULL;
  buffer = read_content(fd, 8192, '\n');
  i = 0;
  while (buffer[i] != '\0')
    std_queue_push(&queue, get_info(buffer, &i));
  free(buffer);
  return (queue);
}

static bool	extract(t_queue		*queue,
			char		*buffer,
			int		archive_fd)
{
  int		fd;
  ssize_t	bytes;
  t_file	*file;

  bytes = 1;
  while (bytes > 0 && buffer[0] != '\n' && buffer[0] != '\0')
    bytes = read(archive_fd, buffer, 1);
  while ((file = (t_file*) std_queue_pop(&queue)) != NULL)
    {
      (buffer != NULL) ? free(buffer) : 0;
      buffer = malloc(file->size);
      if (buffer != NULL && (
	  fd = open(file->name, O_CREAT | O_WRONLY | O_TRUNC, 0666)) != -1)
	{
	  read(archive_fd, buffer, file->size);
	  write(fd, buffer, file->size);
	}
      free(file->name);
      free(file);
    }
  (buffer != NULL) ? free(buffer) : 0;
  return (true);
}

bool		std_decompression(char	*argv[])
{
  int		archive_fd;
  bool		fafalse;
  t_queue	*queue;
  char		*buffer;

  fafalse = false;
  if ((archive_fd = open(argv[1], O_RDONLY)) == -1)
    return (*((bool*)write_error(1, ARCHIVE_FAIL, &fafalse, 1)));
  queue = read_header(archive_fd);
  close(archive_fd);
  if ((buffer = malloc(1)) == NULL)
    return (false);
  buffer[0] = 'a';
  if ((archive_fd = open(argv[1], O_RDONLY)) == -1 || buffer == NULL)
    return (*((bool*)write_error(1, ARCHIVE_FAIL, &fafalse, 1)));
  extract(queue, buffer, archive_fd);
  close(archive_fd);
  return (true);
}

