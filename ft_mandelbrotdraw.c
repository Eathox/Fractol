/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mandelbrotdraw.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:58:21 by pholster       #+#    #+#                */
/*   Updated: 2019/05/21 18:00:47 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	calccount(t_ftl *ftl, int count, float zx, float zy)
{
	double	log_zn;

	if (count < ftl->maxdetail)
	{
		log_zn = log(zx * zx + zy * zy) / 2;
		log_zn = log(log_zn / log(2)) / log(2);
		return ((count + 1) - log_zn);
	}
	return (count);
}

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
	int		count;
	float	zx;
	float	zy;
	float	cx;
	float	cy;

	cx = x * scale[0] + ftl->posx;
	cy = y * scale[1] + ftl->posy;
	zx = 0;
	zy = 0;
	count = 0;
	while (count < ftl->maxdetail && zx * zx + zy * zy < (1 << 16))
	{
		calczxy(&zx, &zy, cx, cy);
		count++;
	}
	ft_putpixel(ftl, x, y, calccount(ftl, count, zx, zy));
}

static void	drawy(t_ftl *ftl, int y, float *scale)
{
	int x;

	x = 0;
	while (x < WINDOW_X)
	{
		drawx(ftl, x, y, scale);
		x++;
	}
	atomic_fetch_add(&ftl->renderd, 1);
}

void		ft_mandelbrotdraw(t_ftl *ftl)
{
	float	scalex;
	float	scaley;
	float	scale[2];
	int		y;

	y = 0;
	ftl->renderd = 0;
	scalex = (ftl->scalex * ftl->zoom) / WINDOW_X;
	scaley = (ftl->scaley * ftl->zoom) / WINDOW_Y;
	scale[0] = scalex;
	scale[1] = scalex;
	ftl->renderd = FALSE;
	while (y < WINDOW_Y)
	{
		ft_poolque(ftl->pool, &drawy, 3, ftl, y, scale);
		y++;
	}
	while (atomic_load(&ftl->renderd) < WINDOW_Y)
		;
	mlx_put_image_to_window(ftl->mlx, ftl->mlx_window, ftl->mlx_image, 0, 0);
}
