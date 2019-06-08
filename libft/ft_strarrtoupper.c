/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrtolower.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 00:29:25 by pholster       #+#    #+#                */
/*   Updated: 2019/05/03 00:29:25 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_strarrtoupper(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
	{
		ft_strtoupper(arr[i]);
		i++;
	}
}
