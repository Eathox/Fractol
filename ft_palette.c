/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_palette.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/08 12:41:51 by pholster       #+#    #+#                */
/*   Updated: 2019/06/08 13:35:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	changecolor(t_ftl *ftl, unsigned int color)
{
	unsigned int	newcolor;

	if (ftl->colors == 1)
		color = (color << 8);
	else if (ftl->colors == 2)
		color = (color << 16);
	else if (ftl->colors == 3)
		color += (color << 8);
	else if (ftl->colors == 4)
		color += (color << 16);
	else if (ftl->colors == 5)
	{
		color = (color << 16);
		color += (color >> 8);
	}
	else if (ftl->colors == 6)
	{
		newcolor = color;
		newcolor += (color << 8);
		newcolor += (color << 16);
		color = newcolor;
	}
	return (color);
}

unsigned int	*palettemaker(t_ftl *ftl)
{
	unsigned int	*palette;
	int				i;
	int				step;

	i = 1;
	step = 1;
	palette = (unsigned int*)ft_memalloc(sizeof(unsigned int) * MAX_DETAIL);
	if (!palette)
		return (NULL);
	while (i < MAX_DETAIL)
	{
		palette[i] += step;
		if (step < 255)
			step += (step < 150) ? 5 : 1;
		if (ftl->colors != 0)
			palette[i] = changecolor(ftl, palette[i]);
		i++;
	}
	return (palette);
}
