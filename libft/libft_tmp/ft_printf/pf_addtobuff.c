/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_addtobuff.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/15 22:58:40 by pholster       #+#    #+#                */
/*   Updated: 2019/04/26 17:57:11 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		pf_addtobuff(t_info *info, char *str, size_t len)
{
	size_t	i;

	if (len + PF_BUFF_LEN > PF_BUFF_SIZE)
	{
		i = PF_BUFF_SIZE - PF_BUFF_LEN;
		ft_memcpy(&PF_BUFF[PF_BUFF_LEN], str, i);
		if (PF_FD == -1)
			ft_lstaddbck(&PF_BUFF_LIST, ft_lstnew(PF_BUFF, PF_BUFF_SIZE));
		else
			write(PF_FD, PF_BUFF, PF_BUFF_SIZE);
		ft_bzero(PF_BUFF, PF_BUFF_SIZE);
		ft_memcpy(PF_BUFF, &str[i], len - i);
		PF_BUFF_LEN = len - i;
	}
	else
	{
		ft_memcpy(&PF_BUFF[PF_BUFF_LEN], str, len);
		PF_BUFF_LEN += len;
	}
	PF_ADDED += len;
}
