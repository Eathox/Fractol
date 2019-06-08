/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_getprecision.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 17:50:26 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		pf_getprecision(t_info *info, const char *str)
{
	int	i;

	i = 1;
	if (str[1] == '*')
	{
		PF_PRECISION = va_arg(PF_ARGS, int);
		if (PF_PRECISION < 0)
			PF_PRECISION = -1;
		return (2);
	}
	PF_PRECISION = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}
