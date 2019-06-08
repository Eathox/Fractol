/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_getflag.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 17:50:26 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	handleconflicts(t_info *info)
{
	PF_FLAG_SPACE = (PF_FLAG_PLUS == FALSE && PF_FLAG_SPACE);
	PF_FLAG_ZERO = (PF_FLAG_MIN == FALSE && PF_FLAG_ZERO);
}

int			pf_getflag(t_info *info, const char *str)
{
	int	i;
	int	spacer;

	i = 0;
	spacer = 0;
	while (i == 0 || ft_chrin(PF_A_FLAG, str[i]) ||
		(ft_chrin(PF_A_SPACER, str[i]) && spacer == 0))
	{
		if (str[i] == '#')
			PF_FLAG_HASH = TRUE;
		else if (str[i] == '0')
			PF_FLAG_ZERO = TRUE;
		else if (str[i] == '-')
			PF_FLAG_MIN = TRUE;
		else if (str[i] == '+')
			PF_FLAG_PLUS = TRUE;
		else if (str[i] == ' ')
			PF_FLAG_SPACE = TRUE;
		else if (str[i] == '\'')
			PF_FLAG_APOST = TRUE;
		spacer = (str[i] != 0);
		i++;
	}
	handleconflicts(info);
	return (i);
}
