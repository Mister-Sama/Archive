/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 25/01/2022 14:00:00
**
** - Lib.h -
**
** *****************************************************************************
*/

#ifndef		__LIB_H__
#define		__LIB_H__

#include	"std_archive.h"

char		*read_content(int	fd,
                              long	size,
                              char	parser);

char		*fuse(const char	*src,
		      const char	*merge,
		      long		size1,
		      long		size2);

char		*std_strdup(char	*s);

size_t		std_strlen(const char	*str);

int		std_atoi(const char	*str);

#endif /* __LIB_H__ */

