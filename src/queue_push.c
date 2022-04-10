/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@csr-pi03.ecole-89.com>
**
** queue_push - 2022
**
** *****************************************************************************
*/

#include        "queue.h"

bool            std_queue_push(t_queue          **que,
                               void             *elem)

{
  t_queue       *nque;

  nque = malloc(sizeof(t_queue));
  if (nque == NULL)
    return (false);
  nque->elem = elem;
  if (*que != NULL)
    {
      (*que)->next = nque;
      nque->head = (*que)->head;
    }
  else
    nque->head = nque;
  *que = nque;
  return (true);
}

