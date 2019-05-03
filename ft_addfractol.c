/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_addfractol.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 01:31:17 by pholster       #+#    #+#                */
/*   Updated: 2019/05/03 01:31:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_ftl	*freeret(t_ftl **ftl, char *error)
{
	ft_memdel((void **)ftl); //TODO add FTL_DEL
	ft_puterror(error);
	return (NULL);
}

t_ftl		*ft_addfractol(t_ftl **ftl, void *fnc)
{
	//TODO adds new t_ftl to ftl
	(void)ftl;
	(void)fnc;
	(void)&freeret;
	return (NULL);
}
