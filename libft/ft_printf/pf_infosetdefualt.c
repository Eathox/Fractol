/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_infosetdefualt.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 12:16:41 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_infosetdefualt(t_info *info)
{
	PF_LENGTH = -1;
	PF_PRECISION = -1;
	PF_TYPE = -1;
	PF_WIDTH = -1;
	PF_VAR_LEN = -1;
	PF_VAR_TYPE = -1;
	PF_VAR_BASE = -1;
	PF_PADADDED = 0;
	PF_FLAG_HASH = 0;
	PF_FLAG_ZERO = 0;
	PF_FLAG_MIN = 0;
	PF_FLAG_PLUS = 0;
	PF_FLAG_SPACE = 0;
	PF_FLAG_APOST = 0;
	PF_ISZERO = FALSE;
	PF_ISNEGATIVE = FALSE;
}
