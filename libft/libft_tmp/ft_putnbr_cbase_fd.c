/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_cbase_fd.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:12:03 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 12:54:07 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_cbase_fd(long long value, int base, int up, int fd)
{
	char				*base_str;
	unsigned long long	num;

	if (up == TRUE)
		base_str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else
		base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	num = (value < 0 && base == 10) ? -value : value;
	if (base < 2 || base > 36)
		return ;
	if (value < 0 && base == 10)
		ft_putchar_fd('-', fd);
	if (num > (unsigned long long)(base - 1))
		ft_putnbr_cbase_fd((num / base), base, up, fd);
	num = base_str[(num % base)];
	ft_putchar_fd(num, fd);
}
