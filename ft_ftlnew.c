/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ftlnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 11:38:14 by pholster       #+#    #+#                */
/*   Updated: 2019/05/22 12:42:57 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_ftl	*freeret(t_ftl *ftl)
{
	mlx_destroy_window(ftl->mlx, ftl->mlx_window);
	mlx_destroy_image(ftl->mlx, ftl->mlx_image);
	free(ftl);
	return (NULL);
}

static void		setscale(t_ftl *ftl)
{
	ftl->scalex = WINDOW_X;
	ftl->scaley = WINDOW_Y;
	if (WINDOW_X < WINDOW_Y)
	{
		ftl->scaley = (ftl->scaley / ftl->scalex);
		ftl->scalex = 1;
	}
	else
	{
		ftl->scalex = (ftl->scalex / ftl->scaley);
		ftl->scaley = 1;
	}
	ftl->posx = -(ftl->scalex * 2);
	ftl->posy = -(ftl->scaley * 2);
	ftl->zoom = 4.2;
}

t_ftl			*ft_ftlnew(void *mlx, t_pool *pool, char *name, void *fnc)
{
	t_ftl	*new;
	int		tmp;

	new = (t_ftl *)ft_memalloc(sizeof(t_ftl));
	if (new == NULL)
		return (NULL);
	name[0] = ft_toupper(name[0]);
	new->mlx = mlx;
	new->pool = pool;
	new->name = name;
	new->active = TRUE;
	new->detail = MAX_DETAIL / 2;
	new->fractol_fnc = fnc;
	setscale(new);
	new->mlx_window = mlx_new_window(new->mlx, WINDOW_X, WINDOW_Y, new->name);
	if (new->mlx_window == NULL)
		return (freeret(new));
	new->mlx_image = mlx_new_image(new->mlx, WINDOW_X, WINDOW_Y);
	if (new->mlx_image == NULL)
		return (freeret(new));
	new->mlx_image_addr = mlx_get_data_addr(new->mlx_image, &tmp, &tmp,
		&(new->endian));
	(void)tmp;
	return (new);
}
