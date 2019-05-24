/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_eventmouseup.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 15:16:34 by pholster       #+#    #+#                */
/*   Updated: 2019/05/24 13:21:24 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	togglehelddown(int mousecode, t_ftl *ftl)
{
	if (mousecode == MOUSE_LEFT)
		ftl->helddown ^= (1 << 0);
	else if (mousecode == MOUSE_RIGHT)
		ftl->helddown ^= (1 << 1);
	return (0);
}

int			ft_eventmouseup(int mousecode, int x, int y, t_ftl *ftl)
{
	if (y < 0)
		return (0);
	if (ftl->active == FALSE)
		return (0);
	togglehelddown(mousecode, ftl);
	(void)x;
	return (0);
}
