/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnchar_fd.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:05:27 by pholster       #+#    #+#                */
/*   Updated: 2019/04/09 17:49:51 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnchar_fd(char c, size_t n, int fd)
{
	while (n > 0)
	{
		write(fd, &c, 1);
		n--;
	}
}
