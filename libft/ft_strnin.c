/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnin.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 18:07:07 by pholster       #+#    #+#                */
/*   Updated: 2019/05/03 01:43:25 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strnin(const char **arr, const char *str, size_t n)
{
	return (ft_strnindex(arr, str, n) != -1);
}
