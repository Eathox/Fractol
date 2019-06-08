/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_issignint.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/14 15:52:55 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		pf_issignint(t_info *info)
{
	if (PF_VAR_TYPE == INT || PF_VAR_TYPE == SHORT || PF_VAR_TYPE == INT_MAX)
		return (TRUE);
	if (PF_VAR_TYPE == LONG || PF_VAR_TYPE == LONG_LONG)
		return (TRUE);
	if (PF_VAR_TYPE == CHAR_I)
		return (TRUE);
	return (FALSE);
}
