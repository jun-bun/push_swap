/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 21:33:01 by juwong            #+#    #+#             */
/*   Updated: 2018/09/09 19:58:09 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <limits.h>
# include <inttypes.h>
# include <wchar.h>
# include <stdio.h>

enum		e_length
{
	none,
	hh,
	h,
	l,
	ll,
	L,
	q,
	j,
	z,
	t,
	p
};

typedef struct		s_arg
{
	char			*format;
	size_t			size;
	char			align;
	char			sign;
	int				zero;
	int				alternate;
	int				width;
	int				precision;
	int				base;
	enum e_length	length;
}					t_arg;

/*
** helpers
*/
void				ft_striter2(char *s, int (*f)(int));
int					ishexzero(char *s);
size_t				ft_intmax_tlen(intmax_t c);

/*
**printf functions
*/
int					ft_printf(const char *format, ...);
char				*print_until(char *str, int *bytes);
char				*s_parse(char *str, va_list ap, int *bytes);
t_arg				*init_args(void);

/*
** parse functions
*/
char				*parse_arg(t_arg *arg, va_list ap, char *str);
char				*parse_flag(t_arg *arg, char *str);
char				*parse_width_precision(t_arg *arg, char *str, va_list ap);
char				*parse_length(t_arg *arg, char *str);

/*
** sign number functions
*/
char				*ft_itoabase(int n, int base);
void				parse_num(char c, t_arg *arg, va_list ap);
intmax_t			*get_num(char c, t_arg *arg, va_list ap, intmax_t *num);
void				getbase(t_arg *arg, char c);
char				*intmax_toa(intmax_t *num, t_arg *arg);

/*
** unsign number functions
*/
void				parse_unum(char c, t_arg *arg, va_list ap);
uintmax_t			*get_unum(char c, t_arg *arg, va_list ap, uintmax_t *num);
char				*uintmax_toa_base(uintmax_t *num, t_arg *arg);

/*
** parse string.c
*/
void				parse_string(char c, t_arg *arg, va_list ap);
void				get_str(char c, t_arg *arg, va_list ap);
void				get_str_wchar(char c, t_arg *arg, va_list ap);

/*
** parse c
*/
void				get_char(char c, t_arg *arg, va_list ap);
void				get_wchar(char c, t_arg *arg, va_list ap);
void				parse_c(char c, t_arg *arg, va_list ap);
void				parse_percent(char c, t_arg *arg);

/*
** wide char
*/
int					wchar_len(wchar_t chr);
size_t				wcharp_len(wchar_t *in);
void				wchar_to_str(wchar_t in, char *str);
wchar_t				*wchar_dup(wchar_t *in);
char				*wchars_to_str(wchar_t *in);
#endif
