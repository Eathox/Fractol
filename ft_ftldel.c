/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ftldel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 11:38:14 by pholster       #+#    #+#                */
/*   Updated: 2019/06/08 12:56:14 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	delete(t_ftl *current, void *mlx)
{
	if (current->mlx_window != NULL)
		mlx_destroy_window(mlx, current->mlx_window);
	if (current->mlx_image != NULL)
		mlx_destroy_image(mlx, current->mlx_image);
	ft_memdel((void **)&(current->palette));
	free(current);
}

void		ft_ftldel(t_ftl **ftl)
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
		delete(current, mlx);
		current = next;
	}
	*ftl = NULL;
	if (mlx != NULL)
		free(mlx);
	ft_pooljoin(pool);
	ft_pooldelete(&pool);
}
