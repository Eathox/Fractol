/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 00:07:34 by pholster       #+#    #+#                */
/*   Updated: 2019/06/07 13:30:02 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_ftl	*ftl;

	ac--;
	ftl = NULL;
	if (ac == 0)
		return (ft_putusage());
	av = &av[1];
	ft_strarrtolower(av);
	ft_strarrsort(av, &ft_strarrsortac);
	if (ft_getfractols(ac, av, &ftl) == NULL)
		return (0);
	ft_init(ftl);
	ft_ftldel(&ftl);
	return (0);
}
