/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_foreach.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 15:28:35 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_foreach(const int *arr, int length, void (*f)(int))
{
	size_t	i;

	i = 0;
	if (f == NULL || arr == NULL)
		return ;
	while (i < (size_t)length)
	{
		f(arr[i]);
		i++;
	}
}
