/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_eventkeyup.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 15:16:34 by pholster       #+#    #+#                */
/*   Updated: 2019/05/03 16:21:36 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	togglehelddown(int keycode, t_ftl *ftl)
{
	if (keycode == KEY_LALT || keycode == KEY_RALT)
		ftl->helddown ^= (1 << 2);
	else if (keycode == KEY_LWIN || keycode == KEY_RWIN)
		ftl->helddown ^= (1 << 3);
	else if (keycode == KEY_LCONTROL || keycode == KEY_RCONTROL)
		ftl->helddown ^= (1 << 4);
	else if (keycode == KEY_LSHIFT || keycode == KEY_RSHIFT)
		ftl->helddown ^= (1 << 5);
	return (0);
}

int			ft_eventkeyup(int keycode, t_ftl *ftl)
{
	if (ftl->active == FALSE)
		return (0);
	togglehelddown(keycode, ftl);
	if (keycode == KEY_EQUALS || keycode == KEY_MINUS)
	{
		ftl->detail += (keycode == KEY_EQUALS) ? DETAIL_STEP : -DETAIL_STEP;
		ftl->detail = ft_constrain(ftl->detail, DETAIL_STEP, MAX_DETAIL);
		ftl->fractol_fnc(ftl);
	}
	if (keycode == KEY_1)
		ftl->zoom -= 0.1;
	if (keycode == KEY_2)
		ftl->zoom += 0.1;
	if (keycode == KEY_RIGHTARROW)
		ftl->posx += 0.1;
	if (keycode == KEY_LEFTARROW)
		ftl->posx -= 0.1;
	if (keycode == KEY_UPARROW)
		ftl->posy += 0.1;
	if (keycode == KEY_DOWNARROW)
		ftl->posy -= 0.1;
	return (0);
}
