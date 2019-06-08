/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pututf8str.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 12:01:12 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:10:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_pututf8str(const t_wchar *str)
{
	ft_pututf8str_fd(str, 1);
}
