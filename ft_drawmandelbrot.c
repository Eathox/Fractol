/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_drawmandelbrot.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:58:21 by pholster       #+#    #+#                */
/*   Updated: 2019/05/16 17:31:51 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "time.h"

static void	drawx(t_ftl *ftl, int x, int y, float *scale)
{
	int		count;
	float	cxy[2];
	float	zxy[2];
	float	tempx;

	cxy[0] = x * scale[0] + ftl->posx;
	cxy[1] = y * scale[1] + ftl->posy;
	zxy[0] = 0;
	zxy[1] = 0;
	count = 0;
	while ((zxy[0] * zxy[0] + zxy[1] * zxy[1] < 4) && (count < ftl->maxdetail))
	{
		tempx = zxy[0] * zxy[0] - zxy[1] * zxy[1] + cxy[0];
		zxy[1] = 2 * zxy[0] * zxy[1] + cxy[1];
		zxy[0] = tempx;
		count++;
	}
	//ft_poolque(ftl->pool, &ft_putpixel, 4, ftl, x, y, count);
	ft_putpixel(ftl, x, y, count);
	if (x == WINDOW_X - 1 && y == WINDOW_Y - 1)
		ftl->renderd = TRUE;
}

void		ft_drawmandelbrot(t_ftl *ftl)
{
	float	scalex;
	float	scaley;
	float	scale[2];
	int		x;
	int		y;

	y = 0;
	scalex = (ftl->scalex * ftl->zoom) / WINDOW_X;
	scaley = (ftl->scaley * ftl->zoom) / WINDOW_Y;
	scale[0] = scalex;
	scale[1] = scalex;
	ftl->renderd = FALSE;
	while (y < WINDOW_Y)
	{
		x = 0;
		while (x < WINDOW_X)
		{
			ft_poolque(ftl->pool, &drawx, 4, ftl, x, y, scale);
			// drawx(ftl, x, y, scale);
			x++;
		}
		y++;
	}
	while (ftl->renderd == FALSE)
		;
	//ft_pooljoin(ftl->pool);
	mlx_put_image_to_window(ftl->mlx, ftl->mlx_window, ftl->mlx_image, 0, 0);
}
