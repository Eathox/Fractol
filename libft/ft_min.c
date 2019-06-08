/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_min.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:40:13 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

long long	ft_min(long long num1, long long num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}
