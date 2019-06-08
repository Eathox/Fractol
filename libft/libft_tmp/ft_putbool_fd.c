/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putbool_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 16:10:37 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:32:52 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putbool_fd(int c, int fd)
{
	if (c == FALSE)
		ft_putstr_fd("FALSE", fd);
	else
		ft_putstr_fd("TRUE", fd);
}
