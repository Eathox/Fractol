/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_next_line.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 16:25:35 by pholster       #+#    #+#                */
/*   Updated: 2019/04/30 18:33:55 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

int			get_next_line(const int fd, char **line)
{
	return (get_next_dline(fd, line, "\n"));
}
