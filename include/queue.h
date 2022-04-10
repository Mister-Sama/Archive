/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** queue - 2022
**
** *****************************************************************************
*/

#include	<stddef.h>
#include	<stdlib.h>
#include	<stdbool.h>

#ifndef         __QUEUE_H__
#define		__QUEUE_H__

typedef struct	u_queue
{
  void		*elem;
  void		*next;
  void		*head;
}		t_queue;

size_t		std_queue_clear(t_queue		**que);

bool		std_queue_push(t_queue		**que,
			       void		*elem);

void		*std_queue_pop(t_queue		**que);

void            *std_queue_top(t_queue		**que);

#endif

