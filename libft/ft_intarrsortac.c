/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intarrsortac.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 23:47:03 by pholster       #+#    #+#                */
/*   Updated: 2019/03/22 23:47:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_intarrsortac(int current, int num)
{
	return (current < num && current - num != 0);
}
