/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mandelbrotdraw.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:58:21 by pholster       #+#    #+#                */
/*   Updated: 2019/06/07 13:34:06 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	calccount(t_ftl *ftl, int count, double zx, double zy)
{
	double	log_zn;

	if (count < ftl->detail)
	{
		log_zn = log(zx * zx + zy * zy) / 2;
		log_zn = log(log_zn / log(2)) / log(2);
		return ((count + 1) - log_zn);
	}
	return (count);
}

static void	calczxy(double *zx, double *zy, double cx, double cy)
{
	double	tempzx;
	double	tempzy;
	double	tempx;

	tempzx = *zx;
	tempzy = *zy;
	tempx = (tempzx * tempzx - tempzy * tempzy + cx);
	*zy = (2 * tempzx * tempzy + cy);
	*zx = tempx;
}

static void	drawx(t_ftl *ftl, int x, int y, double *scale)
{
	int			count;
	double		zx;
	double		zy;
	double		cx;
	double		cy;

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
	count = calccount(ftl, count, zx, zy);
	if (count < ftl->detail && count != 0)
		ft_putpixel(ftl, x, y, count);
}

static void	drawy(t_ftl *ftl, atomic_int *renderd, int y, double *scale)
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
	double		scalex;
	double		scaley;
	double		scale[2];
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
