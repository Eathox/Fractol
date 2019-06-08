/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putpixel.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 13:57:21 by wvan-dam       #+#    #+#                */
/*   Updated: 2019/06/07 19:04:25 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static unsigned int			calc_interpolate(unsigned int color1,
	unsigned int color2, float frac)
{
	unsigned int		result;

	result = (color2 - color1) * frac + color1;
	return (result);
}

static unsigned int			interpolate(unsigned int color1,
	unsigned int color2, float frac)
{
	unsigned int		result;
	unsigned int		rgb1;
	unsigned int		rgb2;

	rgb1 = (color1 >> 16) & 0xff;
	rgb2 = (color2 >> 16) & 0xff;
	result = ((calc_interpolate(rgb1, rgb2, frac) << 16));
	rgb1 = (color1 >> 8) & 0xff;
	rgb2 = (color2 >> 8) & 0xff;
	result += (calc_interpolate(rgb1, rgb2, frac) << 8);
	rgb1 = color1 & 0xff;
	rgb2 = color2 & 0xff;
	result += calc_interpolate(rgb1, rgb2, frac);
	return (result);
}

void		ft_putpixel(t_ftl *ftl, int x, int y, int count)
{
	unsigned int		color;
	unsigned int		color2;
	char				*mem;

	if (x > WINDOW_X || x < 0 || y > WINDOW_Y || y < 0)
		return ;
	mem = (char *)ftl->mlx_image_addr;
	color = ftl->palette[count];
	color2 = ftl->palette[count + 1];
	color = interpolate(color, color2, 0.5);
	ft_memcpy(&mem[((WINDOW_X * y) + x) * 4], &color, 4);
}
