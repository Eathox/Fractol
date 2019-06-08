/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termsetrgbcolor_fd.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:42:21 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:19:48 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_termsetrgbcolor_fd(int r, int g, int b, int fd)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		ft_termresetcolor_fd(fd);
		return ;
	}
	ft_putstr_fd("\e[38;2;", fd);
	ft_putnbr_fd(r, fd);
	ft_putchar_fd(';', fd);
	ft_putnbr_fd(g, fd);
	ft_putchar_fd(';', fd);
	ft_putnbr_fd(b, fd);
	ft_putchar_fd('m', fd);
}
