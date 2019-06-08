/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 13:57:08 by pholster       #+#    #+#                */
/*   Updated: 2019/05/01 15:21:41 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)ft_memalloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	return (str);
}
