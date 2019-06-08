/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strreplace.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 17:48:33 by pholster       #+#    #+#                */
/*   Updated: 2019/06/05 18:26:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	strtotallen(char *str, char *find, size_t len, size_t replen)
{
	char	*ptr;
	size_t	found;
	size_t	findlen;

	found = 0;
	findlen = ft_strlen(find);
	ptr = ft_strstr((const char *)str, (const char *)find);
	while (ptr != NULL)
	{
		ptr = ft_strstr((const char *)ptr + 1, (const char *)find);
		found++;
	}
	return (len - (findlen * found) + (replen * found));
}

static char		*strset(char *ret, char *str, char *find, char *replace)
{
	size_t	i;
	size_t	j;
	size_t	findlen;
	size_t	len;
	char	*ptr;

	i = 0;
	j = 0;
	findlen = ft_strlen(find);
	ptr = ft_strstr((const char *)str, (const char *)find);
	while (ptr != NULL)
	{
		len = (size_t)ret[i] - (size_t)ptr;
		ft_strncpy(&ret[i], &str[j], len);
		i += len;
		j += findlen;
		ft_strcpy(&ret[i], replace);
		i += ft_strlen(replace);
		ptr = ft_strstr((const char *)ptr + 1, (const char *)find);
	}
	ft_strcpy(&ret[i], &str[j]);
	return (ret);
}

char			*ft_strreplace(char *str, char *find, char *replace)
{
	size_t	len;
	size_t	findlen;
	size_t	newlen;
	char	*ret;

	if (str == NULL || find == NULL || replace == NULL || ft_strequ(find, ""))
		return (NULL);
	len = ft_strlen(str);
	findlen = ft_strlen(find);
	newlen = strtotallen(str, find, len, ft_strlen(replace));
	if (newlen == len)
		return (ft_strdup(str));
	ret = ft_strnew(newlen);
	if (ret == NULL)
		return (NULL);
	return (strset(ret, str, find, replace));
}
