/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pututf8.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 12:01:12 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:08:54 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_pututf8(t_wchar c)
{
	ft_pututf8_fd(c, 1);
}
