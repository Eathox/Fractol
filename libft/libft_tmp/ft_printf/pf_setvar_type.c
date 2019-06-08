/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_setvar_type.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 16:04:27 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** TYPES: (% followed by:)
** d or i = int
** u = unsigned int
** b = unsigned binary (base 2)
** o = unsigned octal (base 8)
** x = unsigned hexadecimal (base 16, lowercase)
** X = unsigned hexadecimal (base 16, uppercase)
** f = double
** a = hexdouble (base 16, lowercase)
** A = hexdouble (base 16, uppercase)
** c = unsigned int (If an l modifier is present, wint_t (wide char))
** s = const char * (If an l modifier is present, const T_WCHAR *)
** p = void *
*/

static void	int_type(t_info *info)
{
	if (PF_LENGTH == PF_DOUBLE_H)
		PF_VAR_TYPE = CHAR_I;
	else if (PF_LENGTH == 'h')
		PF_VAR_TYPE = SHORT;
	else if (PF_LENGTH == PF_DOUBLE_L)
		PF_VAR_TYPE = LONG_LONG;
	else if (PF_LENGTH == 'l' || PF_LENGTH == 'z')
		PF_VAR_TYPE = LONG;
	else if (PF_LENGTH == 'j')
		PF_VAR_TYPE = INT_MAX;
	else
		PF_VAR_TYPE = INT;
}

static void	uint_type(t_info *info)
{
	if (PF_LENGTH == PF_DOUBLE_H)
		PF_VAR_TYPE = U_CHAR_I;
	else if (PF_LENGTH == 'h')
		PF_VAR_TYPE = U_SHORT;
	else if (PF_LENGTH == PF_DOUBLE_L)
		PF_VAR_TYPE = U_LONG_LONG;
	else if (PF_LENGTH == 'l')
		PF_VAR_TYPE = U_LONG;
	else if (PF_LENGTH == 'j')
		PF_VAR_TYPE = U_INT_MAX;
	else if (PF_LENGTH == 'z')
		PF_VAR_TYPE = SIZE_T;
	else
		PF_VAR_TYPE = U_INT;
}

static void	double_type(t_info *info)
{
	if (PF_LENGTH == 'L')
		PF_VAR_TYPE = LONG_DOUBLE;
	else
		PF_VAR_TYPE = DOUBLE;
}

void		pf_setvar_type(t_info *info)
{
	if (ft_chrin("di", PF_TYPE))
		int_type(info);
	else if (ft_chrin("uboxX", PF_TYPE))
		uint_type(info);
	else if (PF_TYPE == 'f')
		double_type(info);
	else if (PF_TYPE == '%')
		PF_VAR_TYPE = CHAR;
	else if (PF_TYPE == 'c')
		PF_VAR_TYPE = (PF_LENGTH == 'l') ? T_WCHAR : CHAR;
	else if (PF_TYPE == 's')
		PF_VAR_TYPE = (PF_LENGTH == 'l') ? T_WCHAR_STR : STR;
	else if (PF_TYPE == 'p')
		PF_VAR_TYPE = VOID;
	else
		PF_VAR_TYPE = CHAR;
}
