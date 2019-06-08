/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster       #+#    #+#                */
/*   Updated: 2019/06/07 17:10:37 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include "typedefs.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "threadpool.h"

char		**ft_lsttostrarr(t_list *lst);
char		**ft_strarrcpy_var(char **dst, size_t count, ...);
char		**ft_strarrcpy(char **dst, const char **src);
char		**ft_strarrdup_var(size_t count, ...);
char		**ft_strarrdup(const char **arr);
char		**ft_strarrnew(size_t size);
char		**ft_strdsplit(const char *str, const char *dlm);
char		**ft_strfldnew(size_t x, size_t y, char c);
char		**ft_strsplit(const char *str, char c);
char		*ft_chrtostr(char c);
char		*ft_colorstr(int color);
char		*ft_itoa_base(long long value, int base);
char		*ft_itoa_cbase(long long value, int base, int up);
char		*ft_itoa(long long value);
char		*ft_readfile(int fd);
char		*ft_strcat(char *str1, const char *str2);
char		*ft_strchr(const char *str, int c);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strdtrim(const char *str, const char *dlm);
char		*ft_strdup(const char *str);
char		*ft_strjoin_arr(const char **arr);
char		*ft_strjoin_var(size_t count, ...);
char		*ft_strjoin(const char *str1, const char *str2);
char		*ft_strmap(const char *str, char (*f)(char));
char		*ft_strmapi(const char *str, char (*f)(unsigned int, char));
char		*ft_strncat(char *str1, const char *str2, size_t n);
char		*ft_strncpy(char *dst, const char *src, size_t n);
char		*ft_strndup(const char *str, size_t n);
char		*ft_strnew(size_t size);
char		*ft_strnstr(const char *str, const char *needle, size_t len);
char		*ft_strrchr(const char *str, int c);
char		*ft_strreplace(char *str, char *find, char *replace);
char		*ft_strstr(const char *str, const char *needle);
char		*ft_strsub(const char *str, unsigned int start, size_t len);
char		*ft_strtolower(char *str);
char		*ft_strtoupper(char *str);
char		*ft_strtrim(const char *str);
int			*ft_lsttointarr(t_list *lst);
int			ft_atoi_base(const char *str, int base);
int			ft_atoi(const char *str);
int			ft_chrdin(const char *str, const char *dlm);
int			ft_chrdindex(const char *str, const char *dlm);
int			ft_chrin(const char *str, int c);
int			ft_chrinbytes(long long *bytes, char c);
int			ft_chrindex(const char *str, int c);
int			ft_chrnin(const char *str, int c, size_t n);
int			ft_colorcode(const char *str);
int			ft_colorlcode(const char *str);
int			ft_colorncode(const char *str, size_t n);
int			ft_getchar(void);
int			ft_intarrsortac(int current, int num);
int			ft_intin(const int *arr, int num, size_t len);
int			ft_intlen_base(int value, int base);
int			ft_intlen(int value);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isblank(int c);
int			ft_isdigit(int c);
int			ft_isdigitstr(const char *str);
int			ft_islower(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_isupper(int c);
int			ft_lstsortstrac(t_list *sortlst, t_list *lst);
int			ft_memcmp(const void *str1, const void *str2, size_t len);
int			ft_memequ(const void *str1, const void *str2, size_t len);
int			ft_numlen_base(long long value, int base);
int			ft_numlen(long long value);
int			ft_puterror(const char *str);
int			ft_sqrt(int nb);
int			ft_strarrsortac(char *current, char *str);
int			ft_strcmp_nocase(const char *str1, const char *str2);
int			ft_strcmp(const char *str1, const char *str2);
int			ft_strequ_nocase(const char *str1, const char *str2);
int			ft_strequ(const char *str1, const char *str2);
int			ft_strin(const char **arr, const char *str);
int			ft_strindex(const char **arr, const char *str);
int			ft_strmatch(const char *str, const char *needle);
int			ft_strncmp_nocase(const char *str1, const char *str2, size_t n);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
int			ft_strnequ_nocase(const char *str1, const char *str2, size_t n);
int			ft_strnequ(const char *str1, const char *str2, size_t n);
int			ft_strnin(const char **arr, const char *str, size_t n);
int			ft_strnindex(const char **arr, const char *str, size_t n);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_uintlen_base(unsigned int value, int base);
int			ft_uintlen(unsigned int value);
int			ft_unumlen_base(unsigned long long value, int base);
int			ft_unumlen(unsigned long long value);
long long	ft_abs(long long num);
long long	ft_constrain(long long value, long long num1, long long num2);
long long	ft_inrange(long long value, long long num1, long long num2);
long long	ft_max(long long num1, long long num2);
long long	ft_min(long long num1, long long num2);
long long	ft_pow(long long num, long long pow);
long long	ft_nearestnum(long long value, long long num1, long long num2);
size_t		ft_count_if(const char **str, int (*f)(char *));
size_t		ft_lstlen(t_list *lst);
size_t		ft_lstnlen(t_list *lst, size_t n);
size_t		ft_strarrlen(const char **arr);
size_t		ft_strarrnlen(const char **arr, size_t n);
size_t		ft_strdlen(const char *str, const char *dlm);
size_t		ft_strislen(const char *str, int (*f)(int));
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *str);
size_t		ft_strmatchlen_nocase(const char *str1, const char *str2);
size_t		ft_strmatchlen(const char *str1, const char *str2);
size_t		ft_strnlen(const char *str, size_t n);
size_t		ft_utf8len(t_wchar c);
size_t		ft_utf8strlen(const t_wchar *str);
size_t		ft_utf8strnlen(const t_wchar *str, size_t n);
size_t		ft_wrddcount(const char *str, const char *dlm);
t_list		*ft_intarrtolst(const int *arr, size_t len);
t_list		*ft_lstdup(t_list *lst);
t_list		*ft_lstdupone(t_list *lst);
t_list		*ft_lstfind_content(t_list *lst, void *content, size_t size);
t_list		*ft_lstfind_size(t_list *lst, size_t size);
t_list		*ft_lstfindadd_content(t_list *lst, void *content, size_t size);
t_list		*ft_lstfindadd_size(t_list *lst, size_t size);
t_list		*ft_lstindex(t_list *lst, size_t index);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list		*ft_lstnew(const void *content, size_t content_size);
t_list		*ft_lstunlink(t_list *head, t_list *lst);
t_list		*ft_strarrtolst(const char **arr);
void		*ft_memalloc(size_t size);
void		*ft_memccpy(void *dst, const void *src, int c, size_t len);
void		*ft_memchr(const void *str, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t len);
void		*ft_memdup(const void *src, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memrchr(const void *str, int c, size_t len);
void		*ft_memrcpy(void *dst, const void *src, size_t len);
void		*ft_memreplace(void **str1, const void *str2);
void		*ft_memset(void *str, int c, size_t len);
void		ft_bzero(void *str, size_t len);
void		ft_chrsetbytes(long long *bytes, char *str);
void		ft_foreach(const int *arr, int length, void (*f)(int));
void		ft_intarrsort(int *arr, int (*f)(int, int), size_t len);
void		ft_intarrsortrev(int *arr, int (*f)(int, int), size_t len);
void		ft_lstadd(t_list **head, t_list *new);
void		ft_lstaddbck(t_list **head, t_list *new);
void		ft_lstdel(t_list **head, void (*del)(void *, size_t));
void		ft_lstdelmem(void *content, size_t size);
void		ft_lstdelone(t_list **head, void (*del)(void *, size_t));
void		ft_lstinsert(t_list *head, t_list *lst);
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void		ft_lstrev(t_list **head);
void		ft_lstsort(t_list **head, int (*f)(t_list *, t_list *));
void		ft_lstsortrev(t_list **head, int (*f)(t_list *, t_list *));
void		ft_memdel(void **ap);
void		ft_print_memory(const void *addr, size_t size);
void		ft_putbool_fd(int c, int fd);
void		ft_putbool(int c);
void		ft_putbytes(void *bytes, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putchar(char c);
void		ft_putdouble_fd(long double value, size_t n, int fd);
void		ft_putdouble(long double value, size_t n);
void		ft_putendl_fd(const char *str, int fd);
void		ft_putendl(const char *str);
void		ft_putintarr(const int *arr, size_t len);
void		ft_putintlst(t_list *lst);
void		ft_putline_fd(const char *str, int fd);
void		ft_putline(const char *str);
void		ft_putlstsize(t_list *lst);
void		ft_putnbr_base_fd(long long value, int base, int fd);
void		ft_putnbr_base(long long value, int base);
void		ft_putnbr_cbase_fd(long long value, int base, int up, int fd);
void		ft_putnbr_cbase(long long value, int base, int up);
void		ft_putnbr_fd(long long value, int fd);
void		ft_putnbr(long long value);
void		ft_putnchar_fd(char c, size_t n, int fd);
void		ft_putnchar(char c, size_t n);
void		ft_putnstr_fd(const char *str, size_t n, int fd);
void		ft_putnstr(const char *str, size_t n);
void		ft_putnutf8str (const t_wchar *str, size_t n);
void		ft_putnutf8str_fd(const t_wchar *str, size_t n, int fd);
void		ft_putpointer(const void *pointer);
void		ft_putstr_fd(const char *str, int fd);
void		ft_putstr(const char *str);
void		ft_putstrarr(const char **arr);
void		ft_putstrlst(t_list *lst);
void		ft_putunbr_base_fd(unsigned long long value, int base, int fd);
void		ft_putunbr_base(unsigned long long value, int base);
void		ft_putunbr_cbase(unsigned long long value, int base, int up);
void		ft_putunbr_fd(unsigned long long value, int fd);
void		ft_putunbr(unsigned long long value);
void		ft_pututf8_fd(t_wchar c, int fd);
void		ft_pututf8(t_wchar c);
void		ft_pututf8str_fd(const t_wchar *str, int fd);
void		ft_pututf8strconst (t_wchar *str);
void		ft_strappend(char **dst, const char *src);
void		ft_strarrdel(char ***arr);
void		ft_strarrnsort(char **arr, int (*f)(char *, char *), size_t n);
void		ft_strarrnsortrev(char **arr, int (*f)(char *, char *), size_t n);
void		ft_strarrrev(char **arr);
void		ft_strarrsort(char **arr, int (*f)(char *, char *));
void		ft_strarrsortrev(char **arr, int (*f)(char *, char *));
void		ft_strarrtolower(char **arr);
void		ft_strarrtoupper(char **arr);
void		ft_strclr(char *str);
void		ft_strdel(char **as);
void		ft_striter(const char *str, void (*f)(char *));
void		ft_striteri(const char *str, void (*f)(unsigned int, char *));
void		ft_strrev(char *str);
void		ft_swap(int *a, int *b);
void		ft_termclr_fd(int fd);
void		ft_termclr(void);
void		ft_termcommand_fd(int command, int fd);
void		ft_termcommand(int command);
void		ft_termresetcolor_fd(int fd);
void		ft_termresetcolor(void);
void		ft_termresetcolorbg_fd(int fd);
void		ft_termresetcolorbg(void);
void		ft_termsetcolor_fd(int color, int fd);
void		ft_termsetcolor(int color);
void		ft_termsetcolorbg_fd(int color, int fd);
void		ft_termsetcolorbg(int color);
void		ft_termsetrgbcolor_fd(int r, int g, int b, int fd);
void		ft_termsetrgbcolor(int r, int g, int b);
void		ft_termsetrgbcolorbg_fd(int r, int g, int b, int fd);
void		ft_termsetrgbcolorbg(int r, int g, int b);
double		ft_normalize(long long value, long long *range,
				long long *outputrange);
int			ft_strfldvalid(const char **arr, size_t x, size_t y,
				const char *dlm);
void		ft_putunbr_cbase_fd(unsigned long long value, int base, int up,
				int fd);

#endif
