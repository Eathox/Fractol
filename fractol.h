/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 00:07:34 by pholster       #+#    #+#                */
/*   Updated: 2019/05/03 00:07:34 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "libft/includes/libft.h"
# define MESSAGE_USAGE "./fractol <name of fractol (add lst of fractols)>\n"

//TODO add FTL_DEL
typedef struct	s_ftl
{
	void			*mlx_int;
	void			*mlx_window;
	void			*mlx_image;
	t_pool			*pool;
	void			(*fractol_fnc)();
	struct s_ftl	*next;
}				t_ftl;

t_ftl		*ft_getfractols(int ac, char **av, t_ftl **fractol);
t_ftl		*ft_addfractol(t_ftl **ftl, void *fnc);

#endif
