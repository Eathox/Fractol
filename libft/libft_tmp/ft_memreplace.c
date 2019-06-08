/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memreplace.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 12:11:16 by pholster       #+#    #+#                */
/*   Updated: 2019/06/05 18:04:51 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memreplace(void **str1, const void *str2)
{
	ft_memdel(str1);
	*str1 = (void *)str2;
	return ((void *)str2);
}
