/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 14:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/03/26 11:41:37 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_itoa_base(long long value, int base)
{
	return (ft_itoa_cbase(value, base, TRUE));
}
