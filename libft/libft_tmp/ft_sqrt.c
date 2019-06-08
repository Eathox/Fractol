/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sqrt.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/07 16:33:10 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_sqrt(int nb)
{
	int	n;

	n = 0;
	while (n < nb)
	{
		n++;
		if (n * n == nb)
			return (n);
		if (n * n > nb)
			return (0);
		if (n * n == 46340)
			return (0);
	}
	return (0);
}
