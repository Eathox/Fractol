/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putbool.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 16:10:37 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:33:04 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putbool(int c)
{
	ft_putbool_fd(c, 1);
}
