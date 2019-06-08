/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termcommand.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/19 12:21:06 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:12:52 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_termcommand(int command)
{
	ft_termcommand_fd(command, 1);
}
