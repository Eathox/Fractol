/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_formatchar.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 14:30:25 by pholster       #+#    #+#                */
/*   Updated: 2019/04/12 12:30:34 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_formatchar(t_info *info)
{
	t_wchar	c;

	if (PF_VAR_TYPE == T_WCHAR || PF_TYPE == 'c')
		c = va_arg(PF_ARGS, t_wchar);
	else
		c = '%';
	PF_VAR_LEN = ft_utf8len(c);
	pf_formatpad(info);
	if (PF_VAR_TYPE == T_WCHAR)
		pf_addwchar(info, c);
	else if (PF_TYPE == '%')
		pf_addnstr(info, "%", 1);
	else if (PF_TYPE == 'c')
		pf_addchar(info, (char)c);
}
