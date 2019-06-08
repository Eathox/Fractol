/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strformat_len.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 14:13:23 by pholster       #+#    #+#                */
/*   Updated: 2019/04/30 17:20:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*joinlst(t_info *info)
{
	size_t	i;
	char	*str;
	t_list	*lst;

	i = 0;
	lst = PF_BUFF_LIST;
	str = ft_strnew(PF_ADDED);
	if (str == NULL)
		return (NULL);
	while (lst != NULL)
	{
		if (lst->content != NULL)
			ft_memcpy(&str[i], lst->content, lst->content_size);
		i += lst->content_size;
		lst = lst->next;
	}
	return (str);
}

static char		*freeret(t_info *info)
{
	t_list	*lst;
	char	*str;

	if (PF_BUFF_LEN != 0 && PF_BUFF_LEN != PF_ADDED)
	{
		lst = ft_lstnew(NULL, 0);
		if (lst == NULL)
			return (NULL);
		lst->content = PF_BUFF;
		lst->content_size = PF_BUFF_LEN;
		ft_lstaddbck(&PF_BUFF_LIST, lst);
	}
	if (PF_BUFF_LEN == PF_ADDED)
		str = ft_memdup(PF_BUFF, PF_ADDED);
	else
		str = joinlst(info);
	ft_lstdel(&PF_BUFF_LIST, &ft_lstdelmem);
	if (info != NULL)
		free(info);
	return (str);
}

char			*ft_strformat_len(size_t *len, const char *format, ...)
{
	int		i;
	t_info	*info;

	i = 0;
	if (format == NULL)
		return (NULL);
	info = pf_infonew();
	if (info == NULL)
		return (NULL);
	PF_FD = -1;
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
	if (len != NULL)
		*len = PF_ADDED;
	return (freeret(info));
}
