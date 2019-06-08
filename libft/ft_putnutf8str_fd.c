/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnutf8str_fd.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 12:01:12 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:10:39 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnutf8str_fd(const t_wchar *str, size_t n, int fd)
{
	size_t	i;
	size_t	bytes;
	size_t	len;

	i = 0;
	len = 0;
	if (str == NULL)
	{
		ft_putnstr_fd("(null)", n, fd);
		return ;
	}
	while (str[i] != '\0')
	{
		bytes = ft_utf8len(str[i]);
		if ((len + bytes) > n)
			return ;
		len += bytes;
		ft_pututf8_fd(str[i], fd);
		i++;
	}
}
