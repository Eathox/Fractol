/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intlen_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 14:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_intlen_base(int value, int base)
{
	unsigned int	num;

	num = (value < 0 && base == 10) ? -value : value;
	return (ft_uintlen_base(num, base) + (value < 0 && base == 10));
}
