/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 18:35:27 by pholster       #+#    #+#                */
/*   Updated: 2019/03/16 22:53:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **head, void (*del)(void *, size_t))
{
	if (head == NULL || *head == NULL || del == NULL)
		return ;
	if ((*head)->next != NULL)
		ft_lstdel(&(*head)->next, del);
	ft_lstdelone(head, del);
}
