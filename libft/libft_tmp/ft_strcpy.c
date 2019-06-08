/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:37:30 by pholster       #+#    #+#                */
/*   Updated: 2019/04/30 18:56:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	len;

	len = ft_strlen(src);
	ft_memcpy(dst, src, len);
	dst[len] = '\0';
	return (dst);
}
