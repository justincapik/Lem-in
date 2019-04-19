/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 19:58:30 by klebon            #+#    #+#             */
/*   Updated: 2018/10/01 15:37:27 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*handler_hexa(uintmax_t nb, t_conv *field)
{
	int			size;
	uintmax_t	n;
	char		*str;

	size = set_precision_sizex(nb, field);
	set_malloc_sizeh(nb, field);
	if (!(str = ft_strnewb(field->str_size)))
		return (NULL);
	n = nb;
	while (n)
	{
		str[--size] = (field->fl_type == X) ? "0123456789ABCDEF"[n % 16]
											: "0123456789abcdef"[n % 16];
		n /= 16;
	}
	while (--size >= 0 && field->fl_prec)
		str[size] = '0';
	if (field->fl_hashtag)
		str[1] = (field->fl_type == X) ? 'X' : 'x';
	if (field->fl_hashtag)
		str[0] = '0';
	ft_align_hex(str, field);
	return (str);
}

void	ft_align_hex_zero(char *str, t_conv *field)
{
	int		i;
	int		len;

	i = 0;
	len = (int)ft_strlen(str);
	if (field->fl_hashtag == 0 || (field->fl_hashtag == 1
			&& field->fl_zero == 0))
	{
		ft_memmove(str + (field->str_size - len), str, len);
		while (i < field->str_size - len)
			str[i++] = (field->fl_zero) ? '0' : ' ';
	}
	else
	{
		i = 1;
		ft_memmove(str + (field->str_size - len + 2), str + 2, len - 2);
		while (++i < field->str_size - len + 2)
			str[i] = '0';
	}
}

void	ft_align_hex(char *str, t_conv *field)
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
			ft_align_hex_zero(str, field);
		}
	}
}

char	*select_hexa_handler(t_conv *field, va_list ap)
{
	uintmax_t	tmp;

	if (field->fl_size == h)
		tmp = (uintmax_t)(short unsigned int)va_arg(ap, unsigned int);
	else if (field->fl_size == hh)
		tmp = (uintmax_t)(unsigned char)va_arg(ap, unsigned int);
	else if (field->fl_size == l)
		tmp = (uintmax_t)va_arg(ap, long unsigned int);
	else if (field->fl_size == ll)
		tmp = (uintmax_t)va_arg(ap, unsigned long long int);
	else if (field->fl_size == j)
		tmp = va_arg(ap, uintmax_t);
	else if (field->fl_size == z)
		tmp = (uintmax_t)va_arg(ap, size_t);
	else
		tmp = (uintmax_t)va_arg(ap, unsigned int);
	if (tmp == 0 && field->fl_type != p)
		field->fl_hashtag = 0;
	return (handler_hexa(tmp, field));
}

char	*handle_output_hexa(t_conv *field, va_list ap)
{
	char	*output;

	if (field->fl_type == p)
	{
		field->fl_hashtag = 1;
		field->fl_size = j;
	}
	output = select_hexa_handler(field, ap);
	return (output);
}
