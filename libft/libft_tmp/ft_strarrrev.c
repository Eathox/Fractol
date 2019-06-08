/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrrev.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/24 19:48:17 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_strarrrev(char **arr)
{
	size_t	i;
	size_t	len;
	size_t	half;
	char	*temp;

	i = 0;
	if (arr == NULL)
		return ;
	len = ft_strarrlen((const char **)arr);
	half = (len / 2);
	while (i < half)
	{
		temp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = temp;
		i++;
	}
}
