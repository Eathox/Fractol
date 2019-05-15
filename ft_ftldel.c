/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ftldel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 11:38:14 by pholster       #+#    #+#                */
/*   Updated: 2019/05/03 15:39:43 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_ftldel(t_ftl **ftl)
{
	void	*mlx;
	t_pool	*pool;
	t_ftl	*current;
	t_ftl	*next;

	current = *ftl;
	while (current != NULL)
	{
		if (mlx == NULL)
			mlx = current->mlx;
		if (pool == NULL)
			pool = current->pool;
		next = current->next;
		if (current->mlx_window != NULL)
			mlx_destroy_window(mlx, current->mlx_window);
		if (current->mlx_image != NULL)
			mlx_destroy_image(mlx, current->mlx_image);
		free(current);
		current = next;
	}
	*ftl = NULL;
	if (mlx != NULL)
		free(mlx);
	ft_pooljoin(pool);
	ft_pooldelete(&pool);
}
