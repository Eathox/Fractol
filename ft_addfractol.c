/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_addfractol.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 01:31:17 by pholster       #+#    #+#                */
/*   Updated: 2019/05/03 16:27:09 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_ftl	*freeret(t_ftl **ftl, char *error)
{
	ft_ftldel(ftl);
	ft_puterror(error);
	return (NULL);
}

static void		addftl(t_ftl **ftl, t_ftl *new)
{
	t_ftl	*current;

	current = *ftl;
	if (*ftl == NULL)
	{
		*ftl = new;
		new->head = *ftl;
		return ;
	}
	new->head = *ftl;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

t_ftl			*ft_addfractol(t_ftl **ftl, char *name, void *fnc)
{
	void	*mlx;
	t_pool	*pool;
	t_ftl	*new;

	if (*ftl == NULL)
	{
		mlx = mlx_init();
		pool = ft_poolcreate(POOL_SIZE);
	}
	else
	{
		mlx = (*ftl)->mlx;
		pool = (*ftl)->pool;
	}
	if (pool == NULL || mlx == NULL)
		return (freeret(ftl, "Ft_addfractol: Malloc error\n"));
	new = ft_ftlnew(mlx, pool, name, fnc);
	if (new == NULL)
		return (freeret(ftl, "Ft_ftlnew: Malloc error\n"));
	addftl(ftl, new);
	return (new);
}
