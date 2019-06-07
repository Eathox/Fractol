/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putusage.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 13:34:37 by pholster       #+#    #+#                */
/*   Updated: 2019/06/07 16:32:51 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_putusage(void)
{
	char	*ftactols;

	ftactols = ft_strjoin_var(3, "  Julia\n", "  Mandelbrot\n", "  Tricorn\n");
	ft_dprintf(2, "./fractol <name of fractol>\n%s", ftactols);
	ft_strdel(&ftactols);
	return (0);
}
