/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putpixel.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 13:57:21 by wvan-dam       #+#    #+#                */
/*   Updated: 2019/06/07 16:28:35 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int			*palettemaker(void)
{
	unsigned int	*palette;
	int				i;
	int				step;

	i = 0;
	step = 5;
	palette = (unsigned int*)malloc(sizeof(unsigned int) * MAX_DETAIL);
	while (i < MAX_DETAIL)
	{
		palette[i] = 0;
		i++;
	}
	i = 0;
	while (i < MAX_DETAIL)
	{
		palette[i] += step;
		if (step < 150)
			step += 6;
		else if (step < 255)
			step += 1;
		// if (i >= 50 && i < 100)
			// palette[i] = (palette[i] << 8);
		// if (i >= 100 && i <= 150)
			palette[i] = (palette[i] << 16);
		i++;
	}
	return (palette);
}

unsigned int			calc_interpolate(unsigned int color1, unsigned int color2, double frac)
{
	unsigned int		result;

	result = (color2 - color1) * frac + color1;
	return (result);
}

unsigned int			interpolate(unsigned int color1, unsigned int color2, double frac)
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

unsigned int			*change_palette(unsigned int *colors, double bright, t_ftl *ftl)
{
	if (ftl->colors == 0)
	{
		colors[0] = sqrt(bright);
		colors[2] = sqrt(bright);
	}
	else if (ftl->colors == 1)
		colors[0] = sqrt(bright);
	else if (ftl->colors == 2)
	{
		colors[1] = sqrt(bright);
		colors[2] = sqrt(bright);
	}
	else if (ftl->colors == 3)
		colors[1] = sqrt(bright);
	else if (ftl->colors == 4)
		colors[2] = sqrt(bright);
	else if (ftl->colors == 5)
	{
		colors[0] = sqrt(bright);
		colors[1] = sqrt(bright);
	}
	return (colors);
}

void		ft_putpixel(t_ftl *ftl, int x, int y, int count)
{
	unsigned int		color;
	unsigned int		color2;
	char	*mem;
	// int					count2;

	if (x > WINDOW_X || x < 0 || y > WINDOW_Y || y < 0)
		return ;
	mem = (char *)ftl->mlx_image_addr;
	// color = ft_getcolor(ftl, count, comp);
	// color2 = ft_getcolor(ftl, count + 1, comp);
	// color = interpolate(color, color2, 0.5);
	// count2 = count + 2 - log(log(pow(cx, 2) + pow(cy, 2)) / log(2));

	color = ftl->palette[count];
	color2 = ftl->palette[count + 1];
	color = interpolate(color, color2, 0.5);
	ft_memcpy(&mem[((WINDOW_X * y) + x) * 4], &color, 4);
}
