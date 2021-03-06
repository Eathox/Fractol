/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 00:07:34 by pholster       #+#    #+#                */
/*   Updated: 2019/06/08 13:22:38 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <math.h>
# include "minilibx_macos/mlx.h"
# include "libft/includes/libft.h"
# include "keycodes.h"

# define WINDOW_X			1280
# define WINDOW_Y			720
# define POOL_SIZE			4
# define MAX_DETAIL			150
# define DETAIL_STEP		5
# define COLOR_COUNT		6
# define INTERPOLATE_FRACT	1.5
# define HELDOWN_LEFTMOUSE	(ftl->helddown & (1 << 0))
# define HELDOWN_RIGHTMOUSE	(ftl->helddown & (1 << 1))
# define HELDOWN_ALT		(ftl->helddown & (1 << 2))
# define HELDOWN_WIN		(ftl->helddown & (1 << 3))
# define HELDOWN_CTRL		(ftl->helddown & (1 << 4))
# define HELDOWN_SHIFT		(ftl->helddown & (1 << 5))

typedef struct	s_ftl
{
	void			*mlx;
	void			*mlx_window;
	void			*mlx_image;
	void			*mlx_image_addr;
	t_pool			*pool;
	char			*name;
	unsigned int	*palette;
	void			(*fractol_fnc)();
	char			active;
	int				detail;
	int				helddown;
	int				colors;
	float			zoom;
	float			posx;
	float			posy;
	float			scalex;
	float			scaley;
	float			cx;
	float			cy;
	char			locked;
	struct s_ftl	*next;
	struct s_ftl	*head;
}				t_ftl;

int				ft_eventclose(t_ftl *ftl);
int				ft_eventkeydown(int keycode, t_ftl *ftl);
int				ft_eventkeyup(int keycode, t_ftl *ftl);
int				ft_eventmousedown(int mousecode, int x, int y, t_ftl *ftl);
int				ft_eventmousemove(int x, int y, t_ftl *ftl);
int				ft_eventmouseup(int mousecode, int x, int y, t_ftl *ftl);
int				ft_move(t_ftl *ftl, int keycode);
int				ft_putusage(void);
int				ft_zoom(t_ftl *ftl, int mousecode, int x, int y);
t_ftl			*ft_addfractol(t_ftl **ftl, char *name, void *fnc);
t_ftl			*ft_ftlnew(void *mlx, t_pool *pool, char *name, void *fnc);
t_ftl			*ft_getfractols(int ac, char **av, t_ftl **fractol);
unsigned int	*palettemaker(t_ftl *ftl);
void			ft_ftldel(t_ftl **ftl);
void			ft_ftlsetscale(t_ftl *ftl);
void			ft_init(t_ftl *ftl);
void			ft_juliadraw(t_ftl *ftl);
void			ft_mandelbrotdraw(t_ftl *ftl);
void			ft_putpixel(t_ftl *ftl, int x, int y, int count);
void			ft_puttext(t_ftl *ftl, int x, int y, char *str);
void			ft_tricorndraw(t_ftl *ftl);

#endif
