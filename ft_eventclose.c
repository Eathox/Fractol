/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_eventclose.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 15:16:34 by pholster       #+#    #+#                */
/*   Updated: 2019/05/03 16:26:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_eventclose(t_ftl *ftl)
{
	t_ftl	*current;

	ftl->active = FALSE;
	current = ftl->head;
	while (current != NULL)
	{
		if (current->active)
			return (0);
		current = current->next;
	}
	exit(0);
	return (0);
}
