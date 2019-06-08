/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_infonew.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 14:28:28 by pholster       #+#    #+#                */
/*   Updated: 2019/04/30 18:33:23 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_info	*freeret(t_info **info)
{
	ft_memdel((void **)info);
	return (NULL);
}

t_info			*pf_infonew(void)
{
	t_info	*info;

	info = (t_info *)ft_memalloc(sizeof(t_info));
	if (info == NULL)
		return (NULL);
	PF_BUFF = ft_strnew(PF_BUFF_SIZE);
	if (PF_BUFF == NULL)
		return (freeret(&info));
	pf_infosetdefualt(info);
	PF_ADDED = 0;
	PF_FD = 1;
	PF_BUFF_LEN = 0;
	PF_BUFF_LIST = NULL;
	return (info);
}
