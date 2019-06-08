/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termsetrgbcolor.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:42:21 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:20:12 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_termsetrgbcolor(int r, int g, int b)
{
	ft_termsetrgbcolor_fd(r, g, b, 1);
}
