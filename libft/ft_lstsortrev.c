/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsortrev.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 17:08:43 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static t_list	*join(t_list *head, t_list *half, int (*f)(t_list *, t_list *))
{
	if (head == NULL)
		return (half);
	if (half == NULL)
		return (head);
	if (f(head, half) == FALSE)
	{
		half->next = join(head, half->next, f);
		return (half);
	}
	head->next = join(head->next, half, f);
	return (head);
}

void			ft_lstsortrev(t_list **head, int (*f)(t_list *, t_list *))
{
	t_list	*half;
	t_list	*temp;

	if (f == NULL || head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	temp = ft_lstindex(*head, (ft_lstlen(*head) - 1) / 2);
	half = temp->next;
	temp->next = NULL;
	ft_lstsortrev(head, f);
	ft_lstsortrev(&half, f);
	*head = join(*head, half, f);
}
