/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 00:07:34 by pholster       #+#    #+#                */
/*   Updated: 2019/05/03 15:10:44 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <math.h>
# include "minilibx_macos/mlx.h"
# include "libft/includes/libft.h"
# include "keycodes.h"

# define MESSAGE_USAGE "./fractol <name of fractol (add lst of fractols)>\n"
# define WINDOW_X	512
# define WINDOW_Y	512
# define POOL_SIZE	8

typedef struct	s_ftl
{
	void			*mlx;
	void			*mlx_window;
	void			*mlx_image;
	void			*mlx_image_addr;
	t_pool			*pool;
	char			*name;
	void			(*fractol_fnc)();
	char			helddown;
	struct s_ftl	*next;
}				t_ftl;

t_ftl		*ft_getfractols(int ac, char **av, t_ftl **fractol);
t_ftl		*ft_addfractol(t_ftl **ftl, char *name, void *fnc);
t_ftl 		*ft_ftlnew(void *mlx, t_pool *pool, char *name, void *fnc);
void		ft_ftldel(t_ftl **ftl);

#endif
