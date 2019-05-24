/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_zoom.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 13:09:38 by pholster       #+#    #+#                */
/*   Updated: 2019/05/24 13:22:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoomset(t_ftl *ftl, double zoom)
{
	if (zoom < 0)
		ftl->zoom = 0;
	else
		ftl->zoom = zoom;
}

void		ft_zoom(t_ftl *ftl, int mousecode, int x, int y)
{
	if (mousecode == MOUSE_SCROLLUP)
	{
		zoomset(ftl, (ftl->zoom) / 1.1);
		ftl->fractol_fnc(ftl);
	}
	else if (mousecode == MOUSE_SCROLLDOWN)
	{
		zoomset(ftl, (ftl->zoom) * 1.1);
		ftl->fractol_fnc(ftl);
	}
}
