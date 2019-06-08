/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 14:13:23 by pholster       #+#    #+#                */
/*   Updated: 2019/05/18 14:42:36 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		freeret(t_info *info)
{
	int		ret;

	ret = PF_ADDED;
	write(PF_FD, PF_BUFF, PF_BUFF_LEN);
	if (info != NULL)
	{
		free(PF_BUFF);
		free(info);
	}
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	int		i;
	t_info	*info;

	i = 0;
	if (format == NULL)
		return (-1);
	info = pf_infonew();
	if (info == NULL)
		return (-1);
	va_start(PF_ARGS, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i += pf_distribute(info, &format[i + 1]);
		else
			i += pf_addstr(info, (char *)&format[i]);
		i++;
	}
	va_end(PF_ARGS);
	return (freeret(info));
}
