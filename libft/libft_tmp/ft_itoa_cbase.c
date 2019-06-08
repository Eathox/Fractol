/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_cbase.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 14:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/05/01 15:20:51 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_itoa_cbase(long long value, int base, int up)
{
	unsigned long long	num;
	int					len;
	char				*base_str;
	char				*str;

	num = (value < 0 && base == 10) ? -value : value;
	len = ft_numlen_base(value, base);
	if (base < 2 || base > 36)
		return (NULL);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	if (up == TRUE)
		base_str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else
		base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	while ((len - (value < 0 && base == 10)) != 0)
	{
		str[len - 1] = base_str[(num % base)];
		num = num / base;
		len--;
	}
	if (value < 0 && base == 10)
		str[0] = '-';
	return (str);
}
