/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:18:13 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_strrev(char *str)
{
	size_t	i;
	size_t	len;
	size_t	half;
	int		temp;

	i = 0;
	if (str == NULL)
		return ;
	len = ft_strlen(str);
	half = (len / 2);
	while (i < half)
	{
		temp = str[i];
		str[i] = str[(len - 1) - i];
		str[(len - 1) - i] = temp;
		i++;
	}
}
