/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 18:26:53 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdelone(t_list **head, void (*del)(void *, size_t))
{
	if (head == NULL || *head == NULL)
		return ;
	if (del != NULL)
		del((*head)->content, (*head)->content_size);
	free(*head);
	*head = NULL;
}
