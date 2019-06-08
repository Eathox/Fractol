/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getchar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 17:47:13 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** int		ft_getchar(void)
** {
** 	static int	pointer;
** 	static char	*str = NULL;
**
** 	if (str == NULL)
** 		get_next_line(1, &str);
** 	else if (str[pointer] == '\0')
** 	{
** 		ft_strdel(&str);
** 		pointer = 0;
** 		return ('\n');
** 	}
** 	else
** 		pointer++;
** 	return (str[pointer]);
** }
*/

int		ft_getchar(void)
{
	char	*str;

	get_next_line(1, &str);
	if (str[0] == '\0')
		str[0] = '\n';
	return (str[0]);
}
