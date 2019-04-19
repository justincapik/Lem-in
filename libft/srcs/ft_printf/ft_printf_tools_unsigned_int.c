/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 19:43:31 by klebon            #+#    #+#             */
/*   Updated: 2018/05/25 18:56:39 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_malloc_sizeu(uintmax_t nb, t_conv *field)
{
	uintmax_t	tmp;

	if (nb == 0 && field->fl_prec == 0)
		field->str_size = 0;
	else
		field->str_size = 1;
	tmp = nb;
	while (tmp /= 10)
		++field->str_size;
	field->str_size = (field->str_size < field->fl_prec)
					? field->fl_prec : field->str_size;
	field->str_size = (field->str_size < field->fl_witdth)
					? field->fl_witdth : field->str_size;
}

int		set_precision_sizeu(uintmax_t nb, t_conv *field)
{
	uintmax_t	tmp;
	int			size;

	if (nb == 0 && field->fl_prec == 0)
		size = 0;
	else
		size = 1;
	tmp = nb;
	while (tmp /= 10)
		++size;
	size = (size < field->fl_prec) ? field->fl_prec : size;
	return (size);
}

char	*handler_uns(uintmax_t nb, t_conv *field)
{
	int			size;
	uintmax_t	n;
	char		*str;

	size = set_precision_sizeu(nb, field);
	set_malloc_sizeu(nb, field);
	if (!(str = ft_strnewb(field->str_size)))
		return (NULL);
	n = nb;
	while (n)
	{
		str[--size] = n % 10 + '0';
		n /= 10;
	}
	while (--size >= 0 && field->fl_prec)
		str[size] = '0';
	ft_align_str(str, field);
	return (str);
}

char	*select_uns_int_handler(t_conv *field, va_list ap)
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
	return (handler_uns(tmp, field));
}

char	*handle_output_u(t_conv *field, va_list ap)
{
	char	*output;

	if (field->fl_type == U)
		field->fl_size = l;
	output = select_uns_int_handler(field, ap);
	return (output);
}
