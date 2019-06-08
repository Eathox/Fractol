/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/07 16:33:10 by pholster       #+#    #+#                */
/*   Updated: 2019/05/01 00:21:39 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t	len;
	char	*dup;

	len = ft_strnlen(str, n);
	dup = ft_strnew(len);
	if (dup == NULL)
		return (NULL);
	ft_strncpy(dup, str, len);
	return (dup);
}
