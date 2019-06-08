/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrindex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 22:38:37 by pholster       #+#    #+#                */
/*   Updated: 2019/05/02 19:22:35 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_chrindex(const char *str, int c)
{
	char	*ptr;

	if (str == NULL)
		return (-1);
	ptr = ft_memchr(str, c, ft_strlen(str));
	if (ptr == NULL)
		return (-1);
	return ((int)(((unsigned long)ptr) - ((unsigned long)str)));
}
