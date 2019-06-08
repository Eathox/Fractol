/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putintlst.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 11:40:55 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putintlst(t_list *lst)
{
	int	*n;

	if (lst == NULL)
		return ;
	n = (int *)lst->content;
	ft_putnbr(*n);
	write(1, "\n", 1);
	if (lst->next != NULL)
		ft_putintlst(lst->next);
}
