/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termcommand_fd.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/19 12:21:06 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:12:04 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_termcommand_fd(int command, int fd)
{
	ft_putstr_fd("\e[", fd);
	ft_putnbr_fd(command, fd);
	ft_putchar_fd('m', fd);
}
