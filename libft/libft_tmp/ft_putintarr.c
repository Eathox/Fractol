/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putintarr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 18:18:27 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putintarr(const int *arr, size_t len)
{
	size_t	i;

	i = 0;
	if (arr == NULL)
		return ;
	while (i < len)
	{
		ft_putnbr(arr[i]);
		write(1, "\n", 1);
		i++;
	}
}
