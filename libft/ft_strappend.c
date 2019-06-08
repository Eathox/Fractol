/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strappend.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/17 19:47:57 by pholster       #+#    #+#                */
/*   Updated: 2019/06/05 12:46:43 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_strappend(char **dst, const char *src)
{
	ft_memreplace((void **)dst, ft_strjoin(*dst, src));
}
