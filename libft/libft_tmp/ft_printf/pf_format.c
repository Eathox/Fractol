/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_format.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 14:30:25 by pholster       #+#    #+#                */
/*   Updated: 2019/04/12 11:52:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_format(t_info *info)
{
	if (pf_issignint(info))
		pf_formatnum(info);
	else if (pf_isunsignint(info))
		pf_formatunum(info);
	else if (PF_VAR_TYPE == CHAR || PF_VAR_TYPE == T_WCHAR)
		pf_formatchar(info);
	else if (pf_isstr(info))
		pf_formatstr(info);
	else if (PF_VAR_TYPE == DOUBLE || PF_VAR_TYPE == LONG_DOUBLE)
		pf_formatdouble(info);
	pf_formatbackpad(info);
}
