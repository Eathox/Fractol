/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putpixel.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 13:57:21 by wvan-dam       #+#    #+#                */
/*   Updated: 2019/05/16 14:44:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_putpixel(t_ftl *ftl, int x, int y, int count)
{
	char	*mem;

	mem = (char *)ftl->mlx_image_addr;
	if (x > WINDOW_X || x < 0 || y > WINDOW_Y || y < 0)
		return ;
	ft_memcpy(&mem[((WINDOW_X * y) + x) * 4], ft_getcolor(ftl, count), 4);
}
