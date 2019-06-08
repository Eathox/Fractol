/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunbr_base_fd.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:12:03 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 12:54:27 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putunbr_base_fd(unsigned long long value, int base, int fd)
{
	ft_putunbr_cbase_fd(value, base, TRUE, fd);
}
