/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_getlength.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 17:50:26 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	length(int c)
{
	if (c == PF_DOUBLE_H)
		return (0);
	if (c == 'h')
		return (1);
	if (c == 'l' || c == 'j')
		return (2);
	if (c == 'L' || c == PF_DOUBLE_L || c == 'z')
		return (3);
	return (-1);
}

int			pf_getlength(t_info *info, const char *str)
{
	if (ft_chrin(PF_A_LENGTH_D, PF_LENGTH) && *str == PF_LENGTH)
		PF_LENGTH += *str;
	else if (length(*str) > length(PF_LENGTH))
		PF_LENGTH = *str;
	return (1);
}
