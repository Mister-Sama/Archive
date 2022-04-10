/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** queue_clear - 2022
**
** *****************************************************************************
*/

#include	"queue.h"

size_t		std_queue_clear(t_queue		**que)
{
  size_t	i;
  t_queue	*save;

  i = 0;
  while (*que != NULL)
    {
      save = (*que)->head;
      if (save != (void*) *que)
	(*que)->head = save->next;
      else
	*que = NULL;
      free(save);
      i = i + 1;
    }
  return (i);
}

