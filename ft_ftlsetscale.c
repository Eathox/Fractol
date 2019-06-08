/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ftlsetscale.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 11:38:14 by pholster       #+#    #+#                */
/*   Updated: 2019/06/08 13:18:36 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_ftlsetscale(t_ftl *ftl)
{
	ftl->scalex = WINDOW_X;
	ftl->scaley = WINDOW_Y;
	if (WINDOW_X < WINDOW_Y)
	{
		ftl->scaley = (ftl->scaley / ftl->scalex);
		ftl->scalex = 1;
	}
	else
	{
		ftl->scalex = (ftl->scalex / ftl->scaley);
		ftl->scaley = 1;
	}
	ftl->posx = -(ftl->scalex * 2);
	ftl->posy = -(ftl->scaley * 2);
	ftl->zoom = 4.2;
}
