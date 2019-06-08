/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nearestnum.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 12:56:32 by pholster       #+#    #+#                */
/*   Updated: 2019/06/07 17:08:37 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

long long	ft_nearestnum(long long value, long long num1, long long num2)
{
	long long num1distance;
	long long num2distance;

	num1distance = ft_abs(num1) - ft_abs(value);
	num2distance = ft_abs(num2) - ft_abs(value);
	if (num2distance < num1distance)
		return (num2);
	else
		return (num1);
}
