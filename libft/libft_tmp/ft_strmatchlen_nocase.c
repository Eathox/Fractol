/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmatchlen_nocase.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 17:23:15 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strmatchlen_nocase(const char *str1, const char *str2)
{
	size_t			i;
	unsigned char	temp_a;
	unsigned char	temp_b;

	i = 0;
	while (TRUE)
	{
		temp_a = ft_tolower(str1[i]);
		temp_b = ft_tolower(str2[i]);
		if (temp_a != temp_b)
			return (i);
		if (temp_a == '\0')
			return (i);
		i++;
	}
	return (0);
}
