/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_distribute.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 13:25:57 by pholster       #+#    #+#                */
/*   Updated: 2019/04/29 15:42:59 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		pf_distribute(t_info *info, const char *start)
{
	int	i;

	if (*start == '{')
		i = pf_formatcolor(info, &start[1]);
	else if (*start == '[')
		i = pf_commands(info, &start[1]);
	else
	{
		pf_infosetdefualt(info);
		i = pf_getinfo(info, start);
		pf_format(info);
	}
	return (i);
}
