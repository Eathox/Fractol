/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_threadcreate.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 13:42:11 by pholster       #+#    #+#                */
/*   Updated: 2019/04/25 15:01:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/threadpool.h"

static void	*runfnc(void *param)
{
	t_task *task;

	task = (t_task *)param;
	ft_taskrunfnc(task);
	free(task);
	return (NULL);
}

int			ft_threadcreate(pthread_t *thread, void (*f)(), int count, ...)
{
	int		ret;
	va_list	args;
	t_task	*task;

	if (count > 5 || thread == NULL || f == NULL)
		return (1);
	task = (t_task *)ft_memalloc(sizeof(t_task));
	va_start(args, count);
	ft_tasksetinfo(task, f, count, args);
	va_end(args);
	ret = pthread_create(thread, NULL, &runfnc, (void *)task);
	if (ret == 0)
		return (0);
	free(task);
	return (ret);
}
