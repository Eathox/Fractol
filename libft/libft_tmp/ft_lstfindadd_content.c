/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstfindadd_content.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/21 20:16:41 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstfindadd_content(t_list *lst, void *content, size_t size)
{
	t_list	*newlst;

	while (lst != NULL)
	{
		if (ft_memequ(lst->content, content, size))
			return (lst);
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	newlst = ft_lstnew(content, size);
	if (newlst == NULL)
		return (NULL);
	if (lst != NULL)
		lst->next = newlst;
	return (newlst);
}
