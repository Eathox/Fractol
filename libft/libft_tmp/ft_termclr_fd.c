/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termclr_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/26 14:51:28 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:14:28 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_termclr_fd(int fd)
{
	write(fd, "\e[1;1H\e[2J\n", 12);
}
