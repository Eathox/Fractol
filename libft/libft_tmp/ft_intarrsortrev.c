/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intarrsortrev.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 15:07:28 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_intarrsortrev(int *arr, int (*f)(int, int), size_t len)
{
	size_t	i;
	size_t	j;
	int		current;

	i = 1;
	if (arr == NULL)
		return ;
	while (i < len)
	{
		j = i;
		current = arr[i];
		while (j > 0 && f(current, arr[j - 1]) == FALSE)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = current;
		i++;
	}
}
