/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@csr-pi02.ecole-89.com>
**
** queue_top - 2022
**
** *****************************************************************************
*/

#include	"queue.h"

void		*std_queue_top(t_queue		**que)
{
  if (*que == NULL)
    return (NULL);
  return (((t_queue *)((*que)->head))->elem);
}

