/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:02:42 by klebon            #+#    #+#             */
/*   Updated: 2018/10/30 11:51:59 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*handler_int(uintmax_t nb, t_conv *field)
{
	int			size;
	uintmax_t	n;
	char		*str;

	size = set_precision_sizes(nb, field);
	set_malloc_sizes(nb, field);
	if (!(str = ft_strnewb(field->str_size)))
		return (NULL);
	n = ((intmax_t)nb >= 0) ? (uintmax_t)nb : -(uintmax_t)nb;
	while (n)
	{
		str[--size] = n % 10 + '0';
		n /= 10;
	}
	while (--size >= 0 && field->fl_prec)
		str[size] = '0';
	if ((intmax_t)nb < 0)
		str[0] = '-';
	else if (field->fl_plus || field->fl_space)
		str[0] = (field->fl_plus) ? '+' : ' ';
	ft_align_str(str, field);
	return (str);
}

void	ft_align_str_zero(char *str, t_conv *field)
{
	int		i;
	int		len;

	i = 0;
	len = (int)ft_strlen(str);
	if (field->fl_zero == 0
		|| (str[0] != '-' && str[0] != '+' && str[0] != ' '))
	{
		ft_memmove(str + (field->str_size - len), str, len);
		while (i < field->str_size - len)
			str[i++] = (field->fl_zero && field->fl_prec == 1) ? '0' : ' ';
	}
	else
	{
		ft_memmove(str + (field->str_size - len + 1), str + 1, len - 1);
		while (++i < field->str_size - len + 1)
			str[i] = '0';
	}
}

void	ft_align_str(char *str, t_conv *field)
{
	int		i;

	i = 0;
	if ((int)(ft_strlen(str)) < field->str_size)
	{
		if (field->fl_minus == 1)
		{
			while (str[i])
				i++;
			while (i < field->str_size)
				str[i++] = ' ';
		}
		else
		{
			ft_align_str_zero(str, field);
		}
	}
}

char	*select_int_handler(t_conv *field, va_list ap)
{
	uintmax_t	tmp;

	if (field->fl_size == h)
		tmp = (uintmax_t)(short int)va_arg(ap, int);
	else if (field->fl_size == hh)
		tmp = (uintmax_t)(char)va_arg(ap, int);
	else if (field->fl_size == l)
		tmp = (uintmax_t)va_arg(ap, long int);
	else if (field->fl_size == ll)
		tmp = (uintmax_t)va_arg(ap, long long int);
	else if (field->fl_size == j)
		tmp = (uintmax_t)va_arg(ap, intmax_t);
	else if (field->fl_size == z)
		tmp = (uintmax_t)va_arg(ap, ssize_t);
	else
		tmp = (uintmax_t)va_arg(ap, int);
	return (handler_int(tmp, field));
}

char	*handle_output_i_d(t_conv *field, va_list ap)
{
	char	*output;

	if (field->fl_type == D)
		field->fl_size = l;
	output = select_int_handler(field, ap);
	return (output);
}
