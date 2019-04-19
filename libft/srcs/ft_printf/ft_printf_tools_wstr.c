/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:48:06 by klebon            #+#    #+#             */
/*   Updated: 2018/10/01 15:41:10 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		handler_2oct_wstr(wint_t c, char *output, int *i)
{
	output[(*i)++] = (c >> 6) + 0xC0;
	output[(*i)++] = (c & 0x3F) + 0x80;
}

void		handler_3oct_wstr(wint_t c, char *output, int *i)
{
	output[(*i)++] = (c >> 12) + 0xE0;
	output[(*i)++] = ((c >> 6) & 0x3F) + 0x80;
	output[(*i)++] = (c & 0x3F) + 0x80;
}

void		handler_4oct_wstr(wint_t c, char *output, int *i)
{
	output[(*i)++] = (c >> 18) + 0xF0;
	output[(*i)++] = ((c >> 12) & 0x3F) + 0x80;
	output[(*i)++] = ((c >> 6) & 0x3F) + 0x80;
	output[(*i)++] = (c & 0x3F) + 0x80;
}

void		convert_wstr_to_str(const wint_t *str, char *output, t_conv *field)
{
	int				i;
	int				j;
	int				tmp;

	i = 0;
	j = 0;
	while (str[i] && j <= field->fl_prec)
	{
		tmp = j;
		if (j + 1 <= field->fl_prec
				&& (str[i] <= 0x7F || (MB_CUR_MAX == 1 && str[i] <= 0xFF)))
			output[j++] = (char)str[i];
		else if (j + 2 <= field->fl_prec && str[i] <= 0x7FF)
			handler_2oct_wstr(str[i], output, &j);
		else if (j + 3 <= field->fl_prec && str[i] <= 0xFFFF)
			handler_3oct_wstr(str[i], output, &j);
		else if (j + 4 <= field->fl_prec)
			handler_4oct_wstr(str[i], output, &j);
		++i;
		if (tmp == j)
			break ;
	}
}

char		*handle_output_wstr(t_conv *field, va_list ap)
{
	char			*output;
	const wint_t	*str;

	str = (wint_t *)va_arg(ap, const wint_t *);
	if (str == NULL)
		str = L"(null)";
	if (field->fl_prec != -1)
	{
		if (set_prec_size_wstr(str, field) == 0)
			return (NULL);
	}
	else
	{
		if ((field->str_size = ft_wstrlen(str)) == -1)
			return (NULL);
	}
	if (field->fl_prec == -1)
		field->fl_prec = field->str_size;
	if (field->fl_witdth > field->str_size)
		field->str_size += (field->fl_witdth - field->str_size);
	if (!(output = ft_strnewb(field->str_size)))
		return (NULL);
	convert_wstr_to_str(str, output, field);
	ft_align_wstr(output, field);
	return (output);
}
