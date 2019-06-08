/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 12:26:07 by pholster       #+#    #+#                */
/*   Updated: 2019/05/01 02:08:22 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	return (ft_memrchr(str, c, ft_strlen(str) + 1));
}
