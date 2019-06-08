/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_overflowunsigned.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 18:15:52 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_uintmax	pf_overflowunsigned(t_info *info)
{
	if (PF_VAR_TYPE == U_LONG || PF_VAR_TYPE == VOID)
		return (va_arg(PF_ARGS, unsigned long));
	if (PF_VAR_TYPE == U_LONG_LONG)
		return (va_arg(PF_ARGS, unsigned long long));
	if (PF_VAR_TYPE == U_INT_MAX)
		return (va_arg(PF_ARGS, t_uintmax));
	if (PF_VAR_TYPE == U_CHAR_I)
		return ((unsigned char)va_arg(PF_ARGS, int));
	if (PF_VAR_TYPE == U_SHORT)
		return ((unsigned short)va_arg(PF_ARGS, int));
	if (PF_VAR_TYPE == SIZE_T)
		return (va_arg(PF_ARGS, size_t));
	return (va_arg(PF_ARGS, unsigned int));
}
