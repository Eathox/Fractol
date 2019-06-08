/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 17:30:53 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		pf_addstr(t_info *info, char *str)
{
	size_t	len;

	if (str != NULL)
	{
		len = ft_strdlen(str, "%");
		pf_addnstr(info, str, len);
	}
	else
	{
		len = 6;
		pf_addnstr(info, "(null)", len);
	}
	return ((len > 0) ? len - 1 : len);
}
