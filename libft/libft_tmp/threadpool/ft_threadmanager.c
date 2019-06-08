/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_threadmanager.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:31:26 by pholster       #+#    #+#                */
/*   Updated: 2019/04/26 13:51:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/threadpool.h"

static int	gettask(t_pool *pool, t_thread *self, t_task **task)
{
	char	state;

	if (pool->suspended)
		return (FALSE);
	state = atomic_exchange(&(pool->state), STATE_LOCKED);
	if (state == STATE_LOCKED)
		return (FALSE);
	*task = (t_task *)pool->que;
	if (*task != NULL)
	{
		self->state = STATE_ACTIVE;
		pool->que = (*task)->next;
		if (*task == pool->last)
			pool->last = NULL;
	}
	atomic_store(&(pool->state), state);
	return (*task != NULL);
}

void		*ft_threadmanager(void *param)
{
	int			ret;
	t_task		*task;
	t_pool		*pool;
	t_thread	*self;

	task = NULL;
	self = param;
	pool = self->pool;
	while (pool != NULL && pool->terminating == FALSE)
	{
		ret = gettask(pool, self, &task);
		if (ret != FALSE)
		{
			ft_taskrunfnc(task);
			free(task);
			self->state = STATE_IDLE;
		}
	}
	return (NULL);
}
