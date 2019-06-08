/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 14:13:30 by pholster       #+#    #+#                */
/*   Updated: 2019/04/30 16:49:11 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

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

# define PF_BUFF		info->buff
# define PF_BUFF_LIST	info->buff_list
# define PF_BUFF_LEN	info->buff_len
# define PF_ARGS		info->args
# define PF_ISZERO		info->iszero
# define PF_ISNEGATIVE	info->isnegative
# define PF_FD			info->fd
# define PF_FLAG		info->flag
# define PF_LENGTH		info->length
# define PF_PRECISION	info->precision
# define PF_ADDED		info->added
# define PF_PADADDED	info->padadded
# define PF_TYPE		info->type
# define PF_WIDTH		info->width
# define PF_VAR_LEN		info->var_len
# define PF_VAR_TYPE	info->var_type
# define PF_VAR_BASE	info->var_base
# define PF_A_TYPE		"fdiuboxXcsp%"
# define PF_A_TYPE_L	"FDOUCS"
# define PF_A_FLAG		"#0-+ \'"
# define PF_A_SPACER	",;:_"
# define PF_A_LENGTH	"hlLjz"
# define PF_A_LENGTH_D	"hl"
# define PF_DOUBLE_H	208
# define PF_DOUBLE_L	216
# define PF_FLAG_HASH	PF_FLAG[0]
# define PF_FLAG_ZERO	PF_FLAG[1]
# define PF_FLAG_MIN	PF_FLAG[2]
# define PF_FLAG_PLUS	PF_FLAG[3]
# define PF_FLAG_SPACE	PF_FLAG[4]
# define PF_FLAG_APOST	PF_FLAG[5]
# define PF_BUFF_SIZE	128

enum			e_type
{
	INT,
	INT_MAX,
	SHORT,
	LONG,
	DOUBLE,
	SIZE_T,
	CHAR_I,
	CHAR,
	STR,
	VOID,
	T_WCHAR,
	T_WCHAR_STR,
	LONG_LONG,
	LONG_DOUBLE,
	U_INT,
	U_INT_MAX,
	U_SHORT,
	U_LONG,
	U_LONG_LONG,
	U_CHAR_I
};

/*
** MAYBE CHANGE FLAGS TO BITS LATER
*/

typedef	struct	s_info
{
	char		*buff;
	char		flag[7];
	char		type;
	char		var_base;
	char		iszero;
	char		isnegative;
	int			buff_len;
	int			fd;
	int			length;
	int			added;
	int			padadded;
	int			precision;
	int			var_len;
	int			width;
	enum e_type	var_type;
	va_list		args;
	t_list		*buff_list;
}				t_info;
typedef long long			t_intmax;
typedef unsigned long long	t_uintmax;

char			*ft_strformat(const char *format, ...);
char			*ft_strformat_len(size_t *len, const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_printf(const char *format, ...);
int				pf_addstr(t_info *info, char *str);
int				pf_commands(t_info *info, const char *str);
int				pf_distribute(t_info *info, const char *start);
int				pf_formatcolor(t_info *info, const char *start);
int				pf_getflag(t_info *info, const char *str);
int				pf_getinfo(t_info *info, const char *str);
int				pf_getlength(t_info *info, const char *str);
int				pf_getprecision(t_info *info, const char *str);
int				pf_gettype(t_info *info, const char *str);
int				pf_getwidth(t_info *info, const char *str);
int				pf_ispositiveint(t_info *info);
int				pf_issignint(t_info *info);
int				pf_isstr(t_info *info);
int				pf_isunsignint(t_info *info);
int				pf_iszeropad(t_info *info);
t_info			*pf_infonew(void);
t_intmax		pf_overflowsigned(t_info *info);
t_uintmax		pf_overflowunsigned(t_info *info);
void			pf_addchar(t_info *info, char c);
void			pf_addnstr(t_info *info, char *str, size_t n);
void			pf_addnum(t_info *info, t_intmax value);
void			pf_addtobuff(t_info *info, char *str, size_t len);
void			pf_addunum(t_info *info, t_uintmax value, int len, int base);
void			pf_addwchar(t_info *info, t_wchar c);
void			pf_addwcharstr(t_info *info, t_wchar *str, size_t n);
void			pf_format(t_info *info);
void			pf_formatbackpad(t_info *info);
void			pf_formatchar(t_info *info);
void			pf_formatdouble(t_info *info);
void			pf_formatnum(t_info *info);
void			pf_formatpad(t_info *info);
void			pf_formatstr(t_info *info);
void			pf_formatunum(t_info *info);
void			pf_infosetdefualt(t_info *info);
void			pf_setcolor(t_info *info, int color);
void			pf_setcolorbg(t_info *info, int color);
void			pf_setrgbcolor(t_info *info, int r, int g, int b);
void			pf_setrgbcolorbg(t_info *info, int r, int g, int b);
void			pf_setvar_base(t_info *info);
void			pf_setvar_type(t_info *info);

#endif
