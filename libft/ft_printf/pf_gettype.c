/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_gettype.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 17:50:26 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		pf_gettype(t_info *info, const char *str)
{
	PF_TYPE = *str;
	if (ft_chrin(PF_A_TYPE_L, PF_TYPE))
	{
		PF_TYPE = ft_tolower(PF_TYPE);
		PF_LENGTH = 'l';
	}
	return (-1);
}
