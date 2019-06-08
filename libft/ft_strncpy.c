/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:37:30 by pholster       #+#    #+#                */
/*   Updated: 2019/05/01 00:32:49 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	dstlen;

	dstlen = ft_strnlen(src, n);
	ft_memcpy(dst, src, dstlen);
	ft_bzero(&dst[dstlen], n - dstlen);
	return (dst);
}
