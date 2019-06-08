/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrnew.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 18:29:21 by pholster       #+#    #+#                */
/*   Updated: 2019/04/30 18:52:07 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	**ft_strarrnew(size_t size)
{
	char	**arr;

	arr = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	if (arr == NULL)
		return (NULL);
	return (arr);
}
