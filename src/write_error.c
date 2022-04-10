/*
** *****************************************************************************
** lenny.vigeon
** vigeon.vigeon <lenny.vigeon@student-station>
**
** write_error.c - 2022
**
** ALL DEPENDENCIES IN
**
** Function that make possible to print a message in red (optional)
** in whatever output (even in a file),
** and then return the argument return_value, cast it to return what you want
** *****************************************************************************
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

size_t write_error_strlen(char *str)
{
	if (str[0] == '\0')
		return (0);
	return (1 + write_error_strlen(&str[1]));
}

ssize_t write_error_puts(int    out,
                 char   *s)
{
  return (write(out, s, write_error_strlen(s)));
}

void	*write_error(int	fd,
		     char	*text,
		     void	*return_value,
		     bool	write_red)
{
  ((write_red) ? (write(fd, "\033[0;31m", 8)) : 0);
  write_error_puts(fd, text);
  ((write_red) ? (write(fd, "\033[0;37m", 8)) : 0);
  return (return_value);
}

