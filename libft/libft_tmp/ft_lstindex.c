/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstindex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 22:50:52 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstindex(t_list *lst, size_t index)
{
	size_t	i;

	i = 0;
	while (lst != NULL && i < index)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
