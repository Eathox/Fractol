/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunbr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 15:28:35 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 12:53:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putunbr(unsigned long long value)
{
	ft_putunbr_cbase_fd(value, 10, TRUE, 1);
}
