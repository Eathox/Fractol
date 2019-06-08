/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intin.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_intin(const int *arr, int num, size_t len)
{
	size_t	i;

	i = 0;
	if (arr == NULL)
		return (FALSE);
	while (i < len)
	{
		if (arr[i] == num)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
