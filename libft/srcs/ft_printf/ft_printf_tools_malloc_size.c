/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_malloc_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:43:37 by klebon            #+#    #+#             */
/*   Updated: 2018/10/01 14:13:32 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_malloc_sizes(uintmax_t nb, t_conv *field)
{
	uintmax_t	tmp;

	if (nb == 0 && field->fl_prec == 0)
		field->str_size = 0;
	else
		field->str_size = 1;
	tmp = ((intmax_t)nb >= 0) ? (uintmax_t)nb : -(uintmax_t)nb;
	while (tmp /= 10)
		++field->str_size;
	field->str_size = (field->str_size < field->fl_prec)
					? field->fl_prec : field->str_size;
	field->str_size += ((intmax_t)nb < 0 || field->fl_plus
					|| field->fl_space) ? 1 : 0;
	field->str_size = (field->str_size < field->fl_witdth)
					? field->fl_witdth : field->str_size;
}

void	set_malloc_sizeh(uintmax_t nb, t_conv *field)
{
	uintmax_t	tmp;

	if (nb == 0 && field->fl_prec == 0)
		field->str_size = 0;
	else
		field->str_size = 1;
	tmp = nb;
	while (tmp /= 16)
		field->str_size++;
	field->str_size = (field->str_size < field->fl_prec)
					? field->fl_prec : field->str_size;
	field->str_size += (field->fl_hashtag) ? 2 : 0;
	field->str_size = (field->str_size < field->fl_witdth)
					? field->fl_witdth : field->str_size;
}

void	set_malloc_sizeo(uintmax_t nb, t_conv *field)
{
	uintmax_t	tmp;

	if (nb == 0)
		field->str_size = 0;
	else
		field->str_size = 1;
	tmp = nb;
	while (tmp /= 8)
		++field->str_size;
	field->str_size += (field->fl_hashtag) ? 1 : 0;
	field->str_size = (field->str_size < field->fl_prec)
					? field->fl_prec : field->str_size;
	field->str_size = (field->str_size < field->fl_witdth)
					? field->fl_witdth : field->str_size;
}
