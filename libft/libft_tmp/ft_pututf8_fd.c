/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pututf8_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 12:01:12 by pholster       #+#    #+#                */
/*   Updated: 2019/05/01 01:53:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_pututf8_fd(t_wchar c, int fd)
{
	t_wchar	bit;
	size_t	i;
	size_t	shift;
	size_t	len;

	i = 1;
	len = ft_utf8len(c);
	if (len == 1)
		bit = (0x80 | c) & 0x7f;
	else if (len == 2)
		bit = (0xe0 | (c >> 6)) & 0xdf;
	else if (len == 3)
		bit = (0xf0 | (c >> 12)) & 0xef;
	else if (len == 4)
		bit = (0xf8 | (c >> 18)) & 0xf7;
	write(fd, &bit, 1);
	while (i < len)
	{
		i++;
		shift = 6 * (len - i);
		bit = (0xc0 | (c >> shift)) & 0xbf;
		write(fd, &bit, 1);
	}
}
