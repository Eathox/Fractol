/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:06:48 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 12:55:33 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnstr(const char *str, size_t n)
{
	ft_putnstr_fd(str, n, 1);
}
