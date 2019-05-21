/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 00:07:34 by pholster       #+#    #+#                */
/*   Updated: 2019/05/16 17:30:41 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <math.h>
# include "minilibx_macos/mlx.h"
# include "libft/includes/libft.h"
# include "keycodes.h"

# define MESSAGE_USAGE "./fractol <name of fractol (add lst of fractols)>\n"
# define WINDOW_X	1024
# define WINDOW_Y	1024
# define POOL_SIZE	2
# define MAX_DETAIL 100
# define HELDOWN_LEFTMOUSE	(ftl->helddown & (1 << 0))
# define HELDOWN_RIGHTMOUSE	(ftl->helddown & (1 << 1))
# define HELDOWN_ALT	(ftl->helddown & (1 << 2))
# define HELDOWN_WIN	(ftl->helddown & (1 << 3))
# define HELDOWN_CTRL	(ftl->helddown & (1 << 4))
# define HELDOWN_SHIFT	(ftl->helddown & (1 << 5))

typedef struct	s_ftl
{
	void			*mlx;
	void			*mlx_window;
	void			*mlx_image;
	void			*mlx_image_addr;
	t_pool			*pool;
	char			*name;
	void			(*fractol_fnc)();
	char			active;
	int				endian;
	int				maxdetail;
	int				helddown;
	double			zoom;
	float			posx;
	float			posy;
	float			scalex;
	float			scaley;
	struct s_ftl	*next;
	struct s_ftl	*head;
	char			renderd;
	int				palette[64];
}				t_ftl;

void			ft_putpixel(t_ftl *ftl, int x, int y, int count);
void			ft_drawjulia(t_ftl *ftl);
void			ft_drawmandelbrot(t_ftl *ftl);
int				ft_eventclose(t_ftl *ftl);
int				ft_eventkeydown(int keycode, t_ftl *ftl);
int				ft_eventkeyup(int keycode, t_ftl *ftl);
int				ft_eventmousedown(int mousecode, int x, int y, t_ftl *ftl);
int				ft_eventmousemove(int x, int y, t_ftl *ftl);
int				ft_eventmouseup(int mousecode, int x, int y, t_ftl *ftl);
t_ftl			*ft_addfractol(t_ftl **ftl, char *name, void *fnc);
t_ftl			*ft_getfractols(int ac, char **av, t_ftl **fractol);
t_ftl			*ft_ftlnew(void *mlx, t_pool *pool, char *name, void *fnc);
void			ft_init(t_ftl *ftl);
void			ft_ftldel(t_ftl **ftl);

#endif
