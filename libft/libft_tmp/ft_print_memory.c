/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_memory.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/09 13:03:15 by exam           #+#    #+#                */
/*   Updated: 2019/04/09 18:42:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	putbit(unsigned char c, int size)
{
	char	*base_str;

	base_str = "0123456789abcdef";
	if (size <= 0)
		return ;
	if (size > 1)
		putbit(c / 16, size - 1);
	write(1, &base_str[c % 16], 1);
}

static void	putcontent(unsigned char *content, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (ft_isprint(content[i]) == FALSE)
			write(1, ".", 1);
		else
			write(1, &content[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void		ft_print_memory(const void *addr, size_t size)
{
	unsigned char	*mem;
	size_t			printed;
	size_t			i;

	i = 0;
	mem = (unsigned char *)addr;
	while (i < size)
	{
		i++;
		putbit(mem[i - 1], 2);
		if ((i % 2) == 0)
			write(1, " ", 1);
		if ((i % 16) == 0 || i == size)
		{
			printed = (i % 16) + (i % 2);
			if (printed == 0)
				printed = 16;
			if ((i % 2) != 0)
				write(1, "   ", 3);
			if (printed != 0)
				ft_putnchar(' ', (8 - (printed / 2)) * 5);
			putcontent(&mem[i - printed + (i % 2)], printed - (i % 2));
		}
	}
}
