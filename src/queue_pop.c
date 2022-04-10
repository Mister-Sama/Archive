/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@csr-pi02.ecole-89.com>
**
** queue_pop - 2022
**
** *****************************************************************************
*/

#include	"queue.h"

void		*std_queue_pop(t_queue		**que)
{
  t_queue	*save;
  void		*elem;

  if (*que == NULL)
    return (NULL);
  save = (*que)->head;
  elem = save->elem;
  if (save != (void*) *que)
    (*que)->head = save->next;
  else
    *que = NULL;
  free(save);
  return (elem);
}

