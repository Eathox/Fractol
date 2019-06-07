/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_eventmousedown.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 15:16:34 by pholster       #+#    #+#                */
/*   Updated: 2019/06/07 16:27:54 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	drawret(t_ftl *ftl)
{
	ftl->fractol_fnc(ftl);
	return (0);
}

static int	togglehelddown(int mousecode, t_ftl *ftl)
{
	if (mousecode == MOUSE_LEFT)
		ftl->helddown |= (1 << 0);
	else if (mousecode == MOUSE_RIGHT)
		ftl->helddown |= (1 << 1);
	return (0);
}

int			ft_eventmousedown(int mousecode, int x, int y, t_ftl *ftl)
{
	if (y < 0 || ftl->active == FALSE)
		return (0);
	togglehelddown(mousecode, ftl);
	if (ft_zoom(ftl, mousecode, x, y))
		return (drawret(ftl));
	return (0);
}
