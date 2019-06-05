/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putpixel.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 13:57:21 by wvan-dam       #+#    #+#                */
/*   Updated: 2019/05/24 15:50:04 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		dot_product(t_pixinfo comp)
{
	return ((comp.cx * comp.cx + comp.cy * comp.cy));
}

unsigned int		*change_palette(unsigned int *colors, double bright, t_ftl *ftl)
{
	//colors[0] = sqrt(bright);
	//colors[1] = sqrt(bright);
	//colors[2] = sqrt(bright);
	(void)bright;
	(void)ftl;
	return(colors);
}

unsigned int			ft_getcolor(t_ftl *ftl, int count, t_pixinfo comp)
{
	unsigned int		color;
	unsigned int		colors[3];
	double	bright;

	bright = count - log2(log2(dot_product(comp))) + 20.0;
	colors[0] = 255 * (bright / ftl->detail);
	colors[1] = 255 * (bright / ftl->detail);
	colors[2] = 255 * (bright / ftl->detail);
	change_palette(colors, bright, ftl);
	(void)ftl;
	(void)comp;
	(void)count;
	color = (colors[0] | (colors[1] << 8) | (colors[2] << 16));
	return ((color << 8) >> 8);
}

void		ft_putpixel(t_ftl *ftl, t_pixinfo comp, int count)
{
	unsigned int		color;
	int		lastcolor;
	char	*mem;

	lastcolor = 0;
	if (comp.x > WINDOW_X || comp.x < 0 || comp.y > WINDOW_Y || comp.y < 0)
		return ;
	mem = (char *)ftl->mlx_image_addr;
	if (comp.x != 0)
		lastcolor = mem[((WINDOW_X * comp.y) + (comp.x - 1)) * 4];
	color = ft_getcolor(ftl, count, comp);
	if (comp.x == ftl->debugx && comp.y == ftl->debugy)
	{
		ft_putbytes(&color, 4);
		ft_printf("\nCount: %d Detail: %d Color %d comp.x %d comp.y %d\n", count, ftl->detail, color, comp.cx, comp.cy);
		ftl->debugx = -1;
		ftl->debugy = -1;
	}
	ft_memcpy(&mem[((WINDOW_X * comp.y) + comp.x) * 4], &color, 4);
}
