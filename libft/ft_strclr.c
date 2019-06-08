/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strclr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 13:58:39 by pholster       #+#    #+#                */
/*   Updated: 2019/04/30 18:55:41 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_strclr(char *str)
{
	if (str == NULL)
		return ;
	ft_bzero(str, ft_strlen(str));
}
