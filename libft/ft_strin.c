/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strin.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 18:07:07 by pholster       #+#    #+#                */
/*   Updated: 2019/05/03 01:43:28 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strin(const char **arr, const char *str)
{
	return (ft_strindex(arr, str) != -1);
}
