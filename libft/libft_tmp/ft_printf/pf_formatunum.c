/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_formatunum.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 17:46:23 by pholster       #+#    #+#                */
/*   Updated: 2019/04/29 16:03:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		pf_formatunum(t_info *info)
{
	t_uintmax	num;

	num = pf_overflowunsigned(info);
	PF_ISZERO = (num == 0);
	PF_VAR_LEN = ft_unumlen_base(num, PF_VAR_BASE);
	pf_formatpad(info);
	if (PF_PRECISION >= 0 && PF_ISZERO)
	{
		if (PF_PRECISION > 0 || (PF_TYPE == 'o' && PF_FLAG_HASH))
			pf_addnstr(info, "0", 1);
		else if (PF_WIDTH > 0)
			pf_addnstr(info, " ", 1);
		return ;
	}
	pf_addunum(info, num, PF_VAR_LEN, PF_VAR_BASE);
}
