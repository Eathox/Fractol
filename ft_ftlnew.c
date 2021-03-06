/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ftlnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 11:38:14 by pholster       #+#    #+#                */
/*   Updated: 2019/06/08 13:19:07 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_ftl	*freeret(t_ftl *ftl)
{
	mlx_destroy_window(ftl->mlx, ftl->mlx_window);
	mlx_destroy_image(ftl->mlx, ftl->mlx_image);
	ft_memdel((void **)&(ftl->palette));
	free(ftl);
	return (NULL);
}

static int		setdefualt(t_ftl *ftl)
{
	ftl->active = TRUE;
	ftl->detail = MAX_DETAIL / 2;
	ftl->colors = 0;
	ftl->palette = palettemaker(ftl);
	if (ftl->palette == NULL)
		return (FALSE);
	ft_ftlsetscale(ftl);
	return (TRUE);
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
	new->fractol_fnc = fnc;
	if (setdefualt(new) == FALSE)
		return (freeret(new));
	new->mlx_window = mlx_new_window(new->mlx, WINDOW_X, WINDOW_Y, new->name);
	if (new->mlx_window == NULL)
		return (freeret(new));
	new->mlx_image = mlx_new_image(new->mlx, WINDOW_X, WINDOW_Y);
	if (new->mlx_image == NULL)
		return (freeret(new));
	new->mlx_image_addr = mlx_get_data_addr(new->mlx_image, &tmp, &tmp, &tmp);
	(void)tmp;
	return (new);
}
