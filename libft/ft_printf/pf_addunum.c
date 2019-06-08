/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_addunum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 02:16:09 by pholster       #+#    #+#                */
/*   Updated: 2019/04/29 17:19:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_addunum(t_info *info, t_uintmax value, int len, int base)
{
	char	c;

	if (len == 0)
		return ;
	if (len > 1)
		pf_addunum(info, value / base, len - 1, base);
	c = value % base;
	if (c <= 9)
		c += '0';
	else if (c > 9 && PF_TYPE != 'X')
		c += 'a' - 10;
	else
		c += 'A' - 10;
	pf_addtobuff(info, &c, 1);
}
