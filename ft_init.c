/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 15:16:34 by pholster       #+#    #+#                */
/*   Updated: 2019/05/15 15:59:34 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init(t_ftl *ftl)
{
	void	*window;
	t_ftl	*current;

	current = ftl;
	while (current != NULL)
	{
		window = current->mlx_window;
		mlx_hook(window, 2, (1L << 2), &ft_eventkeydown, current);
		mlx_hook(window, 3, (1L << 3), &ft_eventkeyup, current);
		mlx_hook(window, 4, (1L << 4), &ft_eventmousedown, current);
		mlx_hook(window, 5, (1L << 5), &ft_eventmouseup, current);
		mlx_hook(window, 6, (1L << 6), &ft_eventmousemove, current);
		mlx_hook(window, 17, (1L << 17), &ft_eventclose, current);
		current = current->next;
	}
	mlx_loop(ftl->mlx);
}
