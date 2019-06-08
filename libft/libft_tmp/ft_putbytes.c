/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putbytes.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 16:13:31 by pholster       #+#    #+#                */
/*   Updated: 2019/05/01 02:58:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_putbytes(void *bytes, size_t n)
{
	char	*byts;

	byts = (char *)bytes;
	while (n > 0)
	{
		n--;
		ft_putchar(((byts[n] & (1LL << 0)) != 0) + '0');
		ft_putchar(((byts[n] & (1LL << 1)) != 0) + '0');
		ft_putchar(((byts[n] & (1LL << 2)) != 0) + '0');
		ft_putchar(((byts[n] & (1LL << 3)) != 0) + '0');
		ft_putchar(((byts[n] & (1LL << 4)) != 0) + '0');
		ft_putchar(((byts[n] & (1LL << 5)) != 0) + '0');
		ft_putchar(((byts[n] & (1LL << 6)) != 0) + '0');
		ft_putchar(((byts[n] & (1LL << 7)) != 0) + '0');
		if (n != 0)
			ft_putchar(' ');
	}
}
