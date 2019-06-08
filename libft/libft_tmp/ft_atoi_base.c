/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:30:39 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int				ft_atoi_base(const char *str, int base)
{
	char				*base_str;
	unsigned long long	result;
	unsigned long long	lst_val;
	size_t				i;
	int					isneg;

	result = 0;
	lst_val = result;
	base_str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (base < 2 || base > 36)
		return (0);
	i = ft_strislen(str, &ft_isspace);
	isneg = (str[i] == '-' && base == 10) ? -1 : 1;
	i += (str[i] == '-' || str[i] == '+');
	while (ft_chrnin(base_str, str[i], base) && lst_val <= result)
	{
		lst_val = result;
		result = (result * base) + ft_chrindex(base_str, str[i]);
		i++;
	}
	if (lst_val > result ||
		result > (unsigned long long)(9223372036854775807 + (isneg == -1)))
		return (0 - (isneg == 1));
	return ((int)(result * isneg));
}
