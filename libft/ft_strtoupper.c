/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtoupper.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:20:29 by pholster       #+#    #+#                */
/*   Updated: 2019/05/03 00:33:52 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtoupper(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}
