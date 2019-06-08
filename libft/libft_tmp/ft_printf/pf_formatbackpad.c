/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_formatbackpad.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 14:15:04 by pholster       #+#    #+#                */
/*   Updated: 2019/04/24 14:15:07 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		pf_formatbackpad(t_info *info)
{
	int		len;
	int		i;

	i = PF_PADADDED;
	len = ft_max(0, PF_WIDTH) - PF_VAR_LEN;
	if (PF_FLAG_MIN == FALSE)
		return ;
	while (i < len)
	{
		pf_addtobuff(info, " ", 1);
		i++;
	}
}
