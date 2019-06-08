/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrdindex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 22:38:37 by pholster       #+#    #+#                */
/*   Updated: 2019/05/02 19:22:22 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_chrdindex(const char *str, const char *dlm)
{
	size_t		i;
	long long	bytes[2];

	i = 0;
	if (str == NULL || dlm == NULL)
		return (-1);
	ft_chrsetbytes(bytes, (char *)dlm);
	while (str[i] != '\0')
	{
		if (ft_chrinbytes(bytes, str[i]))
			return ((int)i);
		i++;
	}
	return (-1);
}
