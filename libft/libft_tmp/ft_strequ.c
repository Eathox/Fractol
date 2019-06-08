/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strequ.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:54:42 by pholster       #+#    #+#                */
/*   Updated: 2019/05/01 02:01:57 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strequ(const char *str1, const char *str2)
{
	if (str1 == NULL || str2 == NULL)
		return (FALSE);
	return (ft_strcmp(str1, str2) == 0);
}
