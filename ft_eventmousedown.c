/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_eventmousedown.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 15:16:34 by pholster       #+#    #+#                */
/*   Updated: 2019/05/03 16:03:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	togglehelddown(mousecode, ftl);
	(void)x;
	(void)y;
	return (0);
}
