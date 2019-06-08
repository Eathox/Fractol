/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:03:33 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_striter(const char *str, void (*f)(char *))
{
	size_t	i;

	i = 0;
	if (f == NULL || str == NULL)
		return ;
	while (str[i] != '\0')
	{
		f((char *)&str[i]);
		i++;
	}
}
