/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_isstr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 13:00:18 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		pf_isstr(t_info *info)
{
	return (PF_VAR_TYPE == STR || PF_VAR_TYPE == T_WCHAR_STR);
}
