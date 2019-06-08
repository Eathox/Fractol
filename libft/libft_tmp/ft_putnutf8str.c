/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnutf8str.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 12:01:12 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:07:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnutf8str(const t_wchar *str, size_t n)
{
	ft_putnutf8str_fd(str, n, 1);
}
