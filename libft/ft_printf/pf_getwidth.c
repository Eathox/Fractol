/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_getwidth.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 17:50:26 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		pf_getwidth(t_info *info, const char *str)
{
	int	i;

	i = 1;
	if (*str == '*')
	{
		PF_WIDTH = va_arg(PF_ARGS, int);
		if (PF_WIDTH < 0)
		{
			PF_FLAG_MIN = TRUE;
			PF_WIDTH = -PF_WIDTH;
		}
		return (1);
	}
	PF_WIDTH = ft_atoi(str);
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}
