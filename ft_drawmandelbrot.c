/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_drawmandelbrot.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:58:21 by pholster       #+#    #+#                */
/*   Updated: 2019/05/16 13:04:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_drawmandelbrot(t_ftl *ftl)
{
	ft_putendl(ftl->name);
	// float	xside;
	// float	yside;
	// float	top;
	// float	left;
	// float	xscale, yscale, zx, zy, cx, tempx, cy; 
    // int		x, y; 
    // int		count;

	// left = -1.75; 
    // top = -0.25; 
    // xside = 0.25; 
    // yside = 0.45;
	// xscale = xside / WINDOW_X; 
    // yscale = yside / WINDOW_Y;
	// y = 1;
	//ft_putpixel(ftl, 1, 1, 5);
	// while (y < WINDOW_Y)
	// {
	// 	x = 1;
	// 	while (x < WINDOW_X)
	// 	{
	// 		cx = x * xscale + left;
	// 		cy = y * yscale + top;
	// 		zx = 0;
	// 		zy = 0;
	// 		count = 0;
	// 		while ((zx * zx + zy * zy < 4) && (count < ftl->maxdetail))
	// 		{
	// 			tempx = zx * zx - zy * zy + cx;
	// 			zy = 2 * zx * zy + cy;
	// 			zx = tempx;
	// 			count++;
	// 		}
	// 		//ft_poolque(ftl->pool, &ft_putpixel, 4, ftl, x, y, count);
	// 		//ft_putpixel(ftl, x, y, count);
	// 		x++;
	// 	}
	// 	y++;
	// }
	(void)ftl;
	// (void)zx;
	// (void)zy;
	// (void)x;
	// (void)cy;
	// (void)cx;
	// (void)y;
	// (void)count;
	// (void)tempx;
	//ft_pooljoin(ftl->pool);
	//mlx_put_image_to_window(ftl->mlx, ftl->mlx_window, ftl->mlx_image, 0, 0);
}
