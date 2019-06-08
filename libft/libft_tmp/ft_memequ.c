/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memequ.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:53:02 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_memequ(const void *str1, const void *str2, size_t len)
{
	return (ft_memcmp(str1, str2, len) == 0);
}
