/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_zoom.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 13:09:38 by pholster       #+#    #+#                */
/*   Updated: 2019/05/24 13:43:58 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	zoomset(t_ftl *ftl, double zoom)
{
	if (zoom > 10)
	{
		ftl->zoom = 10;
		return (FALSE);
	}
	ftl->zoom = zoom;
	return (TRUE);
}

int			ft_zoom(t_ftl *ftl, int mousecode, int x, int y)
{
	if (mousecode == MOUSE_SCROLLUP && zoomset(ftl, (ftl->zoom) / 1.1))
		return (TRUE);
	else if (mousecode == MOUSE_SCROLLDOWN && zoomset(ftl, (ftl->zoom) * 1.1))
		return (TRUE);
	(void)x;
	(void)y;
	return (FALSE);
}
