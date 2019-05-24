/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putpixel.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 13:57:21 by wvan-dam       #+#    #+#                */
/*   Updated: 2019/05/24 15:20:33 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// double		dot_product(t_ftl *ftl)
// {
// 	double	result;
// 	int		i;

// 	result = 0.0;
// 	i = 0;
// 	while (i < WINDOW_X)
// 	{

// 	}

// }

int			*change_palette(int *colors, double bright, t_ftl *ftl)
{
	colors[0] = sqrt(bright);
	colors[1] = sqrt(bright);
	//colors[2] = sqrt(bright);
	(void)bright;
	(void)ftl;
	return(colors);
}

int			calc_interpolate(int color1, int color2)
{
	int		result;
	float	fraction;

	fraction = 0.4;
	result = (color2 - color1) * fraction + color1;
	return (result);
}

int			interpolate(int color1, int color2)
{
	int		result;
	int		rgb1;
	int		rgb2;

	rgb1 = (color1 >> 16) & 0xff;
	rgb2 = (color2 >> 16) & 0xff;
	result = ((calc_interpolate(rgb1, rgb2) << 16));
	rgb1 = (color1 >> 8) & 0xff;
	rgb2 = (color2 >> 8) & 0xff;
	result += (calc_interpolate(rgb1, rgb2) << 8);
	rgb1 = color1 & 0xff;
	rgb2 = color2 & 0xff;
	result += calc_interpolate(rgb1, rgb2);
	return (result);
}

int			ft_getcolor(t_ftl *ftl, int count, int lastcolor)
{
	int		colors[3];
	double	bright;
	//int		palette[ftl->detail];
	bright = count - log2(log2(10)) + 4.0;
	colors[0] = 255 * (bright / ftl->detail);
	colors[1] = 255 * (bright / ftl->detail);
	colors[2] = 255 * (bright / ftl->detail);
	change_palette(colors, bright, ftl);
	(void)ftl;
	(void)lastcolor;
	// if (lastcolor == 0 && count != ftl->detail)
	// 	return (colors[0]|(colors[1] << 8)|(colors[2] << 16));
	// if (count == ftl->detail)
	// 	return (0x0);
	// else
	// return(interpolate(colors[0]|(colors[1] << 8)|(colors[2] << 16), lastcolor));
	return (colors[0]|(colors[1] << 8)|(colors[2] << 16));
}

void		ft_putpixel(t_ftl *ftl, int x, int y, int count)
{
	int		color;
	int		lastcolor;
	char	*mem;

	mem = (char *)ftl->mlx_image_addr;
	lastcolor = 0;
	if (x > WINDOW_X || x < 0 || y > WINDOW_Y || y < 0)
		return ;
	if (x != 0)
		lastcolor = mem[((WINDOW_X * y) + (x - 1)) * 4];
	color = ft_getcolor(ftl, count, lastcolor);
	ft_memcpy(&mem[((WINDOW_X * y) + x) * 4], &color, 4);
}
