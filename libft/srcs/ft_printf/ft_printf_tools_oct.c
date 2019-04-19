/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_oct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 20:13:28 by klebon            #+#    #+#             */
/*   Updated: 2018/10/01 15:38:13 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*handler_oct(uintmax_t nb, t_conv *field)
{
	int			size;
	uintmax_t	n;
	char		*str;

	size = set_precision_sizeo(nb, field);
	set_malloc_sizeo(nb, field);
	if (!(str = ft_strnewb(field->str_size)))
		return (NULL);
	n = nb;
	while (n)
	{
		str[--size] = n % 8 + '0';
		n /= 8;
	}
	while (--size >= 0 && field->fl_prec)
		str[size] = '0';
	if (field->fl_hashtag)
		str[0] = '0';
	ft_align_oct(str, field);
	return (str);
}

void	ft_align_oct_zero(char *str, t_conv *field)
{
	int		i;
	int		len;

	i = 0;
	len = (int)ft_strlen(str);
	if (field->fl_zero == 0 || field->fl_hashtag == 0)
	{
		ft_memmove(str + (field->str_size - len), str, len);
		while (i < field->str_size - len)
			str[i++] = (field->fl_zero) ? '0' : ' ';
	}
	else
	{
		ft_memmove(str + (field->str_size - len + 1), str + 1, len - 1);
		while (++i < field->str_size - len + 1)
			str[i] = '0';
	}
}

void	ft_align_oct(char *str, t_conv *field)
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
			ft_align_oct_zero(str, field);
		}
	}
}

char	*select_oct_handler(t_conv *field, va_list ap)
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
	return (handler_oct(tmp, field));
}

char	*handle_output_oct(t_conv *field, va_list ap)
{
	char	*output;

	if (field->fl_type == O)
		field->fl_size = l;
	output = select_oct_handler(field, ap);
	return (output);
}
