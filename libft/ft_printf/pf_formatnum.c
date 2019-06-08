/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_formatnum.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 17:46:23 by pholster       #+#    #+#                */
/*   Updated: 2019/04/16 12:22:25 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		pf_formatnum(t_info *info)
{
	t_intmax	num;

	num = pf_overflowsigned(info);
	PF_ISZERO = (num == 0);
	PF_ISNEGATIVE = (num < 0);
	PF_VAR_LEN = ft_numlen(num) - PF_ISNEGATIVE;
	pf_formatpad(info);
	if (PF_PRECISION == 0 && num == 0)
	{
		if (PF_WIDTH != -1)
			pf_addnstr(info, " ", 1);
		return ;
	}
	pf_addnum(info, num);
}
