/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tricorndraw.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 11:03:10 by wvan-dam       #+#    #+#                */
/*   Updated: 2019/06/08 13:19:36 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	drawinfo(t_ftl *ftl)
{
	int	y;

	y = -14;
	ft_puttext(ftl, 8, y += 18, "ZOOM: SCROLL WHEEL");
	ft_puttext(ftl, 8, y += 18, "MOVE: ARROW KEYS");
	ft_puttext(ftl, 8, y += 18, "RESER POS: R");
	ft_puttext(ftl, 8, y += 18, "DETAIL: + OR -");
	ft_puttext(ftl, 8, y += 18, "COLOR: C");
}

static void	calczxy(float *zx, float *zy, float cx, float cy)
{
	float	xtemp;

	xtemp = (*zx * *zx - *zy * *zy) + cx;
	*zy = (-2 * *zx * *zy) + cy;
	*zx = xtemp;
}

static void	drawx(t_ftl *ftl, int x, int y, float *scale)
{
	int			count;
	float		zx;
	float		zy;
	float		cx;
	float		cy;

	count = 0;
	cx = x * scale[0] + ftl->posx;
	cy = y * scale[1] + ftl->posy;
	zx = 0;
	zy = 0;
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

void		ft_tricorndraw(t_ftl *ftl)
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
	drawinfo(ftl);
	ft_bzero(ftl->mlx_image_addr, (WINDOW_Y * WINDOW_X) * 4);
}
