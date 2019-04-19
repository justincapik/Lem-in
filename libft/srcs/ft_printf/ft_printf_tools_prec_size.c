/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_prec_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:36:42 by klebon            #+#    #+#             */
/*   Updated: 2018/10/01 15:39:43 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		set_precision_sizex(uintmax_t nb, t_conv *field)
{
	uintmax_t	tmp;
	int			size;

	if (nb == 0 && field->fl_prec == 0)
		size = 0;
	else
		size = 1;
	tmp = nb;
	while (tmp /= 16)
		++size;
	size = (size < field->fl_prec) ? field->fl_prec : size;
	size += (field->fl_hashtag) ? 2 : 0;
	return (size);
}

int		set_precision_sizes(uintmax_t nb, t_conv *field)
{
	uintmax_t	tmp;
	int			size;

	if (nb == 0 && field->fl_prec == 0)
		size = 0;
	else
		size = 1;
	tmp = ((intmax_t)nb >= 0) ? (uintmax_t)nb : -(uintmax_t)nb;
	while (tmp /= 10)
		++size;
	size = (size < field->fl_prec) ? field->fl_prec : size;
	size += ((intmax_t)nb < 0 || field->fl_plus || field->fl_space) ? 1 : 0;
	return (size);
}

int		set_precision_sizeo(uintmax_t nb, t_conv *field)
{
	uintmax_t	tmp;
	int			size;

	if (nb == 0 && field->fl_prec == 0)
		size = 0;
	else if (nb == 0)
	{
		size = 0;
		field->fl_hashtag = 0;
	}
	else
		size = 1;
	tmp = nb;
	while (tmp /= 8)
		++size;
	size += (field->fl_hashtag) ? 1 : 0;
	size = (size < field->fl_prec) ? field->fl_prec : size;
	return (size);
}

int		set_prec_size_wstr(const wint_t *str, t_conv *field)
{
	int				i;
	int				tmp;

	i = 0;
	field->str_size = 0;
	while (str[i] && (field->str_size < field->fl_prec))
	{
		tmp = field->str_size;
		if (str[i] < 0 || (MB_CUR_MAX == 1 && str[i] > 0xFF)
				|| (str[i] >= 0xD800 && str[i] <= 0xDFFF) || str[i] > 0x10FFFF)
			return (0);
		else if (str[i] <= 0x7F || (MB_CUR_MAX == 1 && str[i] <= 0xFF))
			field->str_size += (field->str_size + 1 <= field->fl_prec) ? 1 : 0;
		else if (str[i] <= 0x7FF)
			field->str_size += (field->str_size + 2 <= field->fl_prec) ? 2 : 0;
		else if (str[i] <= 0xFFFF)
			field->str_size += (field->str_size + 3 <= field->fl_prec) ? 3 : 0;
		else if (str[i] <= 0x10FFFF)
			field->str_size += (field->str_size + 4 <= field->fl_prec) ? 4 : 0;
		if (tmp == field->str_size)
			return (1);
		++i;
	}
	return (1);
}
