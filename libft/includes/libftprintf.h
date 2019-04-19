/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 21:31:38 by klebon            #+#    #+#             */
/*   Updated: 2019/02/13 09:50:47 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <wchar.h>

enum			e_size
{
	h,
	hh,
	l,
	ll,
	j,
	z
};

enum			e_type
{
	p,
	d,
	i,
	D,
	o,
	O,
	u,
	x,
	X,
	U,
	s,
	S,
	c,
	C,
	percent,
};

typedef struct	s_conv
{
	int			fl_minus;
	int			fl_plus;
	int			fl_zero;
	int			fl_hashtag;
	int			fl_space;
	int			fl_witdth;
	int			fl_prec;
	enum e_size	fl_size;
	enum e_type	fl_type;
	char		*str;
	int			str_size;
}				t_conv;

/*
** Print functions
*/

int				ft_printf(const char *format, ...);
void			ft_putchar(char c);
void			ft_putnbr(int n);
void			ft_putstr(char const *s);

/*
** Tools
*/

size_t			ft_strlen(const char *s);
void			init_struct_conv(t_conv *field);
char			*ft_strnewb(size_t size);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			ft_align_str_zero(char *str, t_conv *field);
void			ft_align_str(char *str, t_conv *field);
void			set_malloc_sizes(uintmax_t nb, t_conv *field);
char			*ft_strdup(const char *s);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
void			set_malloc_sizeu(uintmax_t nb, t_conv *field);
void			set_malloc_sizeo(uintmax_t nb, t_conv *field);
void			set_malloc_sizeu(uintmax_t nb, t_conv *field);
void			init_handler_tab(char *(*f[14])(t_conv *, va_list));
char			*ft_strcpy_s(char *dest, const char *src);
char			*ft_strncpy_s(char *dest, const char *src, size_t n);
int				ft_wstrlen(const wint_t *str);

/*
** Check Flags
*/

void			check_flags(const char **str, t_conv *field);
void			check_width(const char **str, t_conv *field, va_list ap);
ssize_t			check_precision(const char **str, t_conv *field, va_list ap);
void			check_size(const char **str, t_conv *field);
ssize_t			check_type_one(const char **str, t_conv *field);
ssize_t			check_type_two(const char **str, t_conv *field);
ssize_t			check_fields(const char **str, va_list ap, t_conv *field);

/*
** Handle type i and d
*/

char			*handler_int(uintmax_t nb, t_conv *field);
char			*select_int_handler(t_conv *field, va_list ap);
char			*handle_output_i_d(t_conv *field, va_list ap);

/*
** Handle type u
*/

char			*select_uns_int_handler(t_conv *field, va_list ap);
char			*handle_output_u(t_conv *field, va_list ap);
char			*handler_uns(uintmax_t nb, t_conv *field);

/*
** Handle type x and X
*/

char			*handler_hexa(uintmax_t nb, t_conv *field);
char			*select_hexa_handler(t_conv *field, va_list ap);
char			*handle_output_hexa(t_conv *field, va_list ap);
void			ft_align_hex_zero(char *str, t_conv *field);
void			ft_align_hex(char *str, t_conv *field);
int				set_precision_sizex(uintmax_t nb, t_conv *field);
void			set_malloc_sizeh(uintmax_t nb, t_conv *field);

/*
** Handle type o
*/

char			*handler_oct(uintmax_t nb, t_conv *field);
char			*select_oct_handler(t_conv *field, va_list ap);
char			*handle_output_oct(t_conv *field, va_list ap);
void			ft_align_oct_zero(char *str, t_conv *field);
void			ft_align_oct(char *str, t_conv *field);
int				set_precision_sizeo(uintmax_t nb, t_conv *field);

/*
** Handle type c
*/

char			*handle_output_char(t_conv *field, va_list ap);

/*
** Handle type C
*/

unsigned int	ft_bin_size(unsigned int nb);
void			ft_align_wchar(char *str, t_conv *field);
char			*handler_2oct_char(wint_t c, t_conv *field);
char			*handler_3oct_char(wint_t c, t_conv *field);
char			*handler_4oct_char(wint_t c, t_conv *field);
char			*handle_output_wchar(t_conv *field, va_list ap);

/*
** Handle type s
*/

char			*handle_output_str(t_conv *field, va_list ap);
void			ft_align_wstr(char *str, t_conv *field);
int				set_precision_sizes(uintmax_t nb, t_conv *field);

/*
** Handle type S
*/

char			*handle_output_wstr(t_conv *field, va_list ap);
int				set_prec_size_wstr(const wint_t *str, t_conv *field);

#endif
