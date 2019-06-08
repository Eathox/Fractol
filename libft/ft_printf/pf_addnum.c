/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_addnum.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 02:16:09 by pholster       #+#    #+#                */
/*   Updated: 2019/04/29 16:04:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_addnum(t_info *info, t_intmax value)
{
	t_intmax	num;

	num = (value < 0) ? -value : value;
	pf_addunum(info, num, ft_unumlen(num), 10);
}
