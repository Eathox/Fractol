/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intarrtolst.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 10:14:45 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static t_list	*freeret(t_list **lst)
{
	ft_lstdel(lst, &ft_lstdelmem);
	return (NULL);
}

t_list			*ft_intarrtolst(const int *arr, size_t len)
{
	t_list	*returnlst;
	t_list	*prvlst;
	t_list	*newlst;
	int		num;
	size_t	i;

	i = 0;
	if (arr == NULL)
		return (NULL);
	num = arr[i];
	returnlst = ft_lstnew(&num, (sizeof(int) * ft_intlen(num)));
	if (returnlst == NULL)
		return (NULL);
	prvlst = returnlst;
	while (i < len)
	{
		i++;
		num = arr[i];
		newlst = ft_lstnew(&num, (sizeof(int) * ft_intlen(num)));
		if (newlst == NULL)
			return (freeret(&returnlst));
		prvlst->next = newlst;
		prvlst = returnlst;
	}
	return (returnlst);
}
