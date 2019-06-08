/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putline_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 15:26:35 by pholster       #+#    #+#                */
/*   Updated: 2019/04/30 23:49:24 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putline_fd(const char *str, int fd)
{
	size_t	len;
	size_t	half;

	len = ft_strnlen(str, 81);
	if (len > 80)
		return ;
	half = (80 - len) / 2;
	ft_putnchar_fd('-', half, fd);
	ft_putstr_fd(str, fd);
	ft_putnchar_fd('-', half + (len + (half * 2) != 80), fd);
	ft_putchar_fd('\n', fd);
}
