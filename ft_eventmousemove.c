/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_eventmousemove.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 15:16:34 by pholster       #+#    #+#                */
/*   Updated: 2019/06/07 19:04:25 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_eventmousemove(int x, int y, t_ftl *ftl)
{
	if (ftl->active == FALSE || x > WINDOW_X || x < 0 || y > WINDOW_Y || y < 0)
		return (0);
	if (ftl->locked == FALSE && ft_strequ(ftl->name, "Julia"))
	{
		ftl->cx = (((float)x * 3.5) / WINDOW_X) - 2.5;
		ftl->cy = ((float)y / WINDOW_Y);
		ftl->fractol_fnc(ftl);
	}
	return (0);
}
