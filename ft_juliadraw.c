/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_juliadraw.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:58:21 by pholster       #+#    #+#                */
/*   Updated: 2019/06/08 12:35:27 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	drawinfo(t_ftl *ftl)
{
	int	y;

	y = -14;
	ft_puttext(ftl, 8, y += 18, "ZOOM: SCROLL WHEEL");
	ft_puttext(ftl, 8, y += 18, "MOVE: ARROW KEYS");
	ft_puttext(ftl, 8, y += 18, "DETAIL: + OR -");
	ft_puttext(ftl, 8, y += 18, "TOGGLE COMPLEX: SPACE");
	ft_puttext(ftl, 8, y += 18, "COLOR: C");
}

static void	calczxy(float *zx, float *zy, float cx, float cy)
{
	float	tempzx;
	float	tempzy;
	float	tempx;

	tempzx = *zx;
	tempzy = *zy;
	tempx = (tempzx * tempzx - tempzy * tempzy) + cx;
	*zy = (2 * tempzx * tempzy) + cy;
	*zx = tempx;
}

static void	drawx(t_ftl *ftl, int x, int y, float *scale)
{
	int		count;
	float	zx;
	float	zy;
	float	cx;
	float	cy;

	zx = x * scale[0] + ftl->posx;
	zy = y * scale[1] + ftl->posy;
	cx = ftl->cx;
	cy = ftl->cy;
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

void		ft_juliadraw(t_ftl *ftl)
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
