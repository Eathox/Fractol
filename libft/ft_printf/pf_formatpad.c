/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_formatpad.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 14:15:04 by pholster       #+#    #+#                */
/*   Updated: 2019/04/24 14:15:22 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	addprefix(t_info *info, char *str, size_t n)
{
	if (n == 0)
		return (0);
	pf_addnstr(info, str, n);
	if (PF_VAR_TYPE == VOID && PF_WIDTH <= PF_PRECISION)
		return (0);
	if (PF_PRECISION > PF_WIDTH && ft_strequ(str, "0") == FALSE)
		return (0);
	return ((int)n);
}

static void	addpad(t_info *info, int len, char c)
{
	int		i;

	i = 0;
	while (i < len)
	{
		pf_addtobuff(info, &c, 1);
		i++;
	}
}

static void	addzero(t_info *info, int len, int space, char *prfx)
{
	int		prelen;
	char	c;

	prelen = ft_strlen(prfx);
	c = (pf_iszeropad(info)) ? '0' : ' ';
	len = len - ft_max(0, space);
	if (PF_VAR_TYPE == VOID || PF_ISZERO == FALSE)
		len -= addprefix(info, prfx, prelen);
	else if (ft_tolower(prfx[1]) != 'x' && PF_TYPE != 'o')
		len -= addprefix(info, prfx, prelen);
	if (len > 0 && (PF_FLAG_MIN == FALSE || c != ' '))
		addpad(info, len, c);
}

static char	*getprefix(t_info *info)
{
	if (PF_ISNEGATIVE)
		return ("-");
	if (PF_FLAG_PLUS && pf_ispositiveint(info))
		return ("+");
	if (PF_FLAG_SPACE && pf_ispositiveint(info))
		return (" ");
	if ((PF_FLAG_HASH && ft_chrin("xX", PF_TYPE)) || PF_VAR_TYPE == VOID)
		return ((PF_TYPE == 'X') ? "0X" : "0x");
	if (PF_FLAG_HASH && PF_TYPE == 'o' && PF_ISZERO == FALSE &&
		PF_PRECISION <= PF_VAR_LEN)
		return ("0");
	return ("");
}

void		pf_formatpad(t_info *info)
{
	char	*prfx;
	int		prelen;
	int		len;
	int		space;

	prfx = getprefix(info);
	prelen = ft_strlen(prfx);
	PF_PADADDED = PF_ADDED;
	if (PF_PRECISION > PF_WIDTH && pf_isstr(info) == FALSE)
		len = ft_max(0, PF_PRECISION) - PF_VAR_LEN;
	else
		len = ft_max(0, PF_WIDTH) - PF_VAR_LEN;
	space = ft_max(0, PF_WIDTH) - ft_max(PF_VAR_LEN, PF_PRECISION);
	if (PF_VAR_TYPE == VOID || PF_ISZERO == FALSE)
		space -= prelen;
	else if (ft_tolower(prfx[1]) != 'x' && PF_TYPE != 'o')
		space -= prelen;
	if (PF_FLAG_ZERO &&
		(PF_PRECISION == -1 || (PF_PRECISION == 0 && PF_FLAG_HASH == FALSE)))
		space = 0;
	if (space > 0 && PF_FLAG_MIN == FALSE)
		addpad(info, space, ' ');
	addzero(info, len, space, prfx);
	PF_PADADDED = PF_ADDED - PF_PADADDED;
}
