/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mandelbrotdraw.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:58:21 by pholster       #+#    #+#                */
/*   Updated: 2019/06/07 19:21:44 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calczxy(float *zx, float *zy, float cx, float cy)
{
	float	tempzx;
	float	tempzy;
	float	tempx;

	tempzx = *zx;
	tempzy = *zy;
	tempx = (tempzx * tempzx - tempzy * tempzy + cx);
	*zy = (2 * tempzx * tempzy + cy);
	*zx = tempx;
}

static void	drawx(t_ftl *ftl, int x, int y, float *scale)
{
	int			count;
	float		zx;
	float		zy;
	float		cx;
	float		cy;

	cx = x * scale[0] + ftl->posx;
	cy = y * scale[1] + ftl->posy;
	zx = 0;
	zy = 0;
	count = 0;
	while (count < ftl->detail && zx * zx + zy * zy < 4)
	{
		calczxy(&zx, &zy, cx, cy);
		count++;
	}
	if (count < ftl->detail && count != 0)
		ft_putpixel(ftl, x, y, count);
}

static void	drawy(t_ftl *ftl, atomic_int *renderd, int y, float *scale)
{
	int x;

	x = 0;
	while (x < WINDOW_X)
	{
		drawx(ftl, x, y, scale);
		x++;
	}
	atomic_fetch_add(renderd, 1);
}

void		ft_mandelbrotdraw(t_ftl *ftl)
{
	atomic_int	renderd;
	float		scalex;
	float		scaley;
	float		scale[2];
	int			y;

	y = 0;
	renderd = 0;
	scalex = (ftl->scalex * ftl->zoom) / WINDOW_X;
	scaley = (ftl->scaley * ftl->zoom) / WINDOW_Y;
	scale[0] = scalex;
	scale[1] = scalex;
	while (y < WINDOW_Y)
	{
		ft_poolque(ftl->pool, &drawy, 4, ftl, &renderd, y, scale);
		y++;
	}
	while (atomic_load(&renderd) < WINDOW_Y)
		;
	mlx_put_image_to_window(ftl->mlx, ftl->mlx_window, ftl->mlx_image, 0, 0);
	ft_bzero(ftl->mlx_image_addr, (WINDOW_X * WINDOW_Y) * 4);
}
