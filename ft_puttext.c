/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puttext.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/08 12:27:22 by pholster       #+#    #+#                */
/*   Updated: 2019/06/08 12:36:57 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_puttext(t_ftl *ftl, int x, int y, char *str)
{
	mlx_string_put(ftl->mlx, ftl->mlx_window, x, y, 0xFFFFFF, str);
}
