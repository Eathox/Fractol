/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_commands.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 15:47:54 by pholster       #+#    #+#                */
/*   Updated: 2019/04/28 02:10:22 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		pf_commands(t_info *info, const char *str)
{
	int	len;

	len = ft_strislen(str, &ft_isdigit);
	if (*str == ']')
	{
		pf_addtobuff(info, "\e[0m", 5);
		return (2);
	}
	if (ft_strnequ_nocase(str, "clr]", 4))
	{
		pf_addtobuff(info, "\e[1;1H\e[2J\n", 12);
		return (5);
	}
	if (len != 0 && str[len] == ']')
	{
		pf_addtobuff(info, "\e[", 3);
		pf_addtobuff(info, (char *)str, len);
		pf_addtobuff(info, "m", 1);
		return (2 + len);
	}
	return (0);
}
