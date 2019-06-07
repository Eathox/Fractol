/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_eventkeydown.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 15:16:34 by pholster       #+#    #+#                */
/*   Updated: 2019/06/07 17:04:25 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	drawret(t_ftl *ftl)
{
	ftl->fractol_fnc(ftl);
	return (0);
}

static int	togglehelddown(int keycode, t_ftl *ftl)
{
	if (keycode == KEY_LALT || keycode == KEY_RALT)
		ftl->helddown |= (1 << 2);
	else if (keycode == KEY_LWIN || keycode == KEY_RWIN)
		ftl->helddown |= (1 << 3);
	else if (keycode == KEY_LCONTROL || keycode == KEY_RCONTROL)
		ftl->helddown |= (1 << 4);
	else if (keycode == KEY_LSHIFT || keycode == KEY_RSHIFT)
		ftl->helddown |= (1 << 5);
	else if (keycode == KEY_SPACE)
		ftl->locked = (ftl->locked) ? FALSE : TRUE;
	return (0);
}

int			ft_eventkeydown(int keycode, t_ftl *ftl)
{
	if (ftl->active == FALSE)
		return (0);
	togglehelddown(keycode, ftl);
	if ((HELDOWN_CTRL && keycode == KEY_C) || keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(ftl->mlx, ftl->mlx_window);
		ft_eventclose(ftl);
		return (0);
	}
	if (keycode == KEY_EQUALS || keycode == KEY_MINUS)
	{
		ftl->detail += (keycode == KEY_EQUALS) ? DETAIL_STEP : -DETAIL_STEP;
		ftl->detail = ft_constrain(ftl->detail, DETAIL_STEP, MAX_DETAIL);
		return (drawret(ftl));
	}
	if (ft_move(ftl, keycode))
		return (drawret(ftl));
	if (keycode == KEY_C)
	{
		ftl->colors = ((ftl->colors + 1) > 5) ? 0 : ftl->colors + 1;
		ftl->palette = palettemaker(ftl);
		return (drawret(ftl));
	}
	return (0);
}
