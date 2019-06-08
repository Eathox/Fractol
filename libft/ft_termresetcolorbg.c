/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termresetcolorbg.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:42:21 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:16:00 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_termresetcolorbg(void)
{
	ft_termresetcolorbg_fd(1);
}
