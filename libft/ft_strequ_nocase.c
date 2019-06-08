/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strequ_nocase.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:54:42 by pholster       #+#    #+#                */
/*   Updated: 2019/05/01 02:01:49 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strequ_nocase(const char *str1, const char *str2)
{
	if (str1 == NULL || str2 == NULL)
		return (FALSE);
	return (ft_strcmp_nocase(str1, str2) == 0);
}
