/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdupone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 15:54:49 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstdupone(t_list *lst)
{
	t_list	*duplst;

	if (lst == NULL)
		return (NULL);
	duplst = ft_lstnew(lst->content, lst->content_size);
	if (duplst == NULL)
		return (NULL);
	return (duplst);
}
