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

int			ft_getcolor(t_ftl *ftl, int count)
{

	if (count == 0)
 		return (0xffffff);
	if (count >= 110 && count <= 450)
		return (0x00FF00);
	if (count >= 12 && count <= 30)
		return (0xFF0000);
	if (count == 11)
		return (0x00FF00);
	if (count == 10)
		return (0x0fffff);
	if (count == 9)
		return (0xFF0000);
	if (count == 8)
		return (0x00FF00);
	if (count == 7)
		return (0x0fffff);
	if (count == 6)
		return (0xFF0000);
	if (count == 5)
		return (0x00FF00);
	if (count == 4)
		return (0x00FF00);
	if (count == 3)
		return (0x00FF00);
	if (count == 2)
		return (0x00FF00);
	else
		return (0x0);
	(void)ftl;
}

void		ft_putpixel(t_ftl *ftl, int x, int y, int count)
{
	int		color;
	char	*mem;

	mem = (char *)ftl->mlx_image_addr;
	if (x > WINDOW_X || x < 0 || y > WINDOW_Y || y < 0)
		return ;
	color = ft_getcolor(ftl, count);
	ft_memcpy(&mem[((WINDOW_X * y) + x) * 4], &color, 4);
}
