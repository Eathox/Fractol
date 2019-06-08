/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 13:56:40 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 23:51:59 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstadd(t_list **head, t_list *new)
{
	if (head == NULL || new == NULL)
		return ;
	new->next = *head;
	*head = new;
}
