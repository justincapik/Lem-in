/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fields.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 12:33:40 by klebon            #+#    #+#             */
/*   Updated: 2018/10/30 12:32:51 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	check_flags(const char **str, t_conv *field)
{
	while (**str == '-' || **str == '+' || **str == '0' || **str == '#'
			|| **str == ' ')
	{
		if (**str == '-')
			field->fl_minus = 1;
		else if (**str == '+')
			field->fl_plus = 1;
		else if (**str == '0')
			field->fl_zero = 1;
		else if (**str == '#')
			field->fl_hashtag = 1;
		else if (**str == ' ')
			field->fl_space = 1;
		(*str)++;
	}
}

void	check_width(const char **str, t_conv *field, va_list ap)
{
	int	tmp;

	if (**str == '*')
	{
		tmp = va_arg(ap, int);
		field->fl_witdth = (tmp < 0) ? -tmp : tmp;
		if (tmp < 0)
			field->fl_minus = 1;
		(*str)++;
	}
	else
	{
		field->fl_witdth = 0;
		while (**str >= '0' && **str <= '9')
		{
			field->fl_witdth *= 10;
			field->fl_witdth += **str - '0';
			(*str)++;
		}
	}
}

ssize_t	check_precision(const char **str, t_conv *field, va_list ap)
{
	int	tmp;

	if (**str == '.')
	{
		(*str)++;
		if (**str == '*')
		{
			if ((tmp = va_arg(ap, int)) >= 0)
				field->fl_prec = tmp;
			(*str)++;
		}
		else if (**str >= '0' && **str <= '9')
		{
			field->fl_prec = 0;
			while (**str >= '0' && **str <= '9')
			{
				field->fl_prec *= 10;
				field->fl_prec += **str - '0';
				(*str)++;
			}
		}
		else
			field->fl_prec = 0;
	}
	return (1);
}

void	check_size(const char **str, t_conv *field)
{
	if (**str == 'h' || **str == 'l' || **str == 'j' || **str == 'z')
	{
		if (**str == 'h' && *(*str + 1) == 'h')
		{
			field->fl_size = hh;
			(*str)++;
		}
		else if (**str == 'h')
			field->fl_size = h;
		else if (**str == 'l' && *(*str + 1) == 'l')
		{
			field->fl_size = ll;
			(*str)++;
		}
		else if (**str == 'l')
			field->fl_size = l;
		else if (**str == 'j')
			field->fl_size = l;
		else if (**str == 'z')
			field->fl_size = l;
		(*str)++;
	}
}

ssize_t	check_fields(const char **str, va_list ap, t_conv *field)
{
	init_struct_conv(field);
	check_flags(str, field);
	check_width(str, field, ap);
	if (!(check_precision(str, field, ap)))
		return (0);
	check_size(str, field);
	if (!(check_type_one(str, field)) || !(check_type_two(str, field)))
		return (0);
	if ((field->fl_type != d && field->fl_type != D && field->fl_type != i)
		|| field->fl_plus == 1)
		field->fl_space = 0;
	if (field->fl_type < s && field->fl_prec != -1)
		field->fl_zero = 0;
	else if (field->fl_type < s && field->fl_prec == -1)
		field->fl_prec = 1;
	if (field->fl_type == C && field->fl_size == h)
		field->fl_type = c;
	if (field->fl_type == c && field->fl_size == l)
		field->fl_type = C;
	if (field->fl_type == S && field->fl_size == h)
		field->fl_type = s;
	if (field->fl_type == s && field->fl_size == l)
		field->fl_type = S;
	return (1);
}
