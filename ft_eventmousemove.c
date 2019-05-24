/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_eventmousemove.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 15:16:34 by pholster       #+#    #+#                */
/*   Updated: 2019/05/24 13:21:21 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_eventmousemove(int x, int y, t_ftl *ftl)
{
	if (y < 0)
		return (0);
	if (ftl->active == FALSE)
		return (0);
	(void)x;
	return (0);
}
