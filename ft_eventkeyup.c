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
	return (0);
}
