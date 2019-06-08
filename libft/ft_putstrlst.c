/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstrlst.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 11:40:55 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putstrlst(t_list *lst)
{
	if (lst == NULL)
		return ;
	ft_putendl((char *)lst->content);
	if (lst->next != NULL)
		ft_putstrlst(lst->next);
}
