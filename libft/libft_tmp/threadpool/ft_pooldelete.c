/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pooldelete.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:53:48 by pholster       #+#    #+#                */
/*   Updated: 2019/05/02 12:31:42 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/threadpool.h"

static void	delque(t_pool *pool)
{
	t_task	*que;
	t_task	*temp;

	que = pool->que;
	pool->que = NULL;
	while (que != NULL)
	{
		temp = que;
		que = que->next;
		free(temp);
	}
}

void		ft_pooldelete(t_pool **pool)
{
	t_thread	*thread;
	int			i;

	i = 0;
	if (pool == NULL || *pool == NULL)
		return ;
	(*pool)->terminating = TRUE;
	while (i < (*pool)->size && (*pool)->threads[i] != NULL)
	{
		thread = (*pool)->threads[i];
		pthread_join(thread->thread, NULL);
		free(thread);
		i++;
	}
	ft_memdel((void **)&((*pool)->threads));
	delque(*pool);
	ft_memdel((void **)pool);
}
