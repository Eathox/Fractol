/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putpixel.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 13:57:21 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/05/16 13:57:22 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_putpixel(t_ftl *ftl, int x, int y, int count)
{
	// int		color[11];
	if (x > WINDOW_X || x < 0 || y > WINDOW_Y || y < 0)
		return ;
	(void)ftl;
	(void)count;
	// color[0] = 0x000000;
	// color[1] = 0x000010;
	// color[2] = 0x001010;
	// color[3] = 0x101010;
	// color[4] = 0x000001;
	// color[5] = 0x010101;
	// color[6] = 0x000011;
	// color[7] = 0x001111;
	// color[8] = 0x111111;
	// color[9] = 0x000222;
	// color[10] = 0x222222;
	// ((char *)ftl->mlx_image_addr)[(WINDOW_X * y) + x] = color[count];
}