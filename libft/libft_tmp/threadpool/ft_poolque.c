/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_poolque.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 21:13:06 by pholster       #+#    #+#                */
/*   Updated: 2019/04/26 13:51:48 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/threadpool.h"

static int	freeret(t_pool *pool, t_task *task, char state)
{
	free(task);
	atomic_store(&(pool->state), state);
	return (FALSE);
}

int			ft_poolque(t_pool *pool, void (*f)(), int count, ...)
{
	va_list		params;
	char		state;
	t_task		*task;

	if (count > 5 || pool == NULL || pool->terminating || f == NULL)
		return (FALSE);
	task = (t_task *)ft_memalloc(sizeof(t_task));
	if (task == NULL)
		return (FALSE);
	state = atomic_exchange(&(pool->state), STATE_LOCKED);
	while (state == STATE_LOCKED)
		state = atomic_exchange(&(pool->state), STATE_LOCKED);
	va_start(params, count);
	ft_tasksetinfo(task, f, count, params);
	va_end(params);
	if (pool->terminating)
		return (freeret(pool, task, state));
	if (pool->last == NULL)
		pool->que = task;
	else
		pool->last->next = task;
	pool->last = task;
	atomic_store(&(pool->state), state);
	return (TRUE);
}
