/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrdup_var.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 16:18:39 by pholster       #+#    #+#                */
/*   Updated: 2019/05/01 12:59:58 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	**ft_strarrdup_var(size_t count, ...)
{
	size_t	i;
	va_list	args;
	char	**dup;

	i = 0;
	dup = ft_strarrnew(count);
	if (dup == NULL)
		return (NULL);
	va_start(args, count);
	while (i < count)
	{
		dup[i] = ft_strdup(va_arg(args, char *));
		if (dup[i] == NULL)
		{
			va_end(args);
			ft_strarrdel(&dup);
			return (NULL);
		}
		i++;
	}
	va_end(args);
	return (dup);
}
