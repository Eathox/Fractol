/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_move.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 13:09:38 by pholster       #+#    #+#                */
/*   Updated: 2019/05/24 13:47:47 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	posset(t_ftl *ftl, double posx, double posy)
{
	ftl->posx = posx;
	ftl->posy = posy;
	return (TRUE);
}

int			ft_move(t_ftl *ftl, int keycode)
{
	if (keycode == KEY_RIGHTARROW)
		return (posset(ftl, ftl->posx / 1.1, ftl->posy));
	else if (keycode == KEY_LEFTARROW)
		return (posset(ftl, ftl->posx * 1.1, ftl->posy));
	else if (keycode == KEY_DOWNARROW)
		return (posset(ftl, ftl->posx, ftl->posy / 1.1));
	else if (keycode == KEY_UPARROW)
		return (posset(ftl, ftl->posx, ftl->posy * 1.1));
	return (FALSE);
}
