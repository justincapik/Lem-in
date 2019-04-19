/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_wchar_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 18:10:11 by klebon            #+#    #+#             */
/*   Updated: 2018/10/01 15:40:54 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** I have to handle minus, width
*/

void			ft_align_wchar(char *str, t_conv *field)
{
	int		i;
	int		len;

	len = (int)ft_strlen(str);
	len = (len) ? len : 1;
	if (len < field->str_size)
	{
		if (field->fl_minus == 1)
		{
			i = 1;
			while (str[i])
				++i;
			while (i < field->str_size)
				str[i++] = ' ';
		}
		else
		{
			i = 0;
			ft_memmove(str + (field->str_size - len), str, len);
			while (i < field->str_size - len)
				str[i++] = (field->fl_zero) ? '0' : ' ';
		}
	}
}

char			*handler_2oct_char(wint_t c, t_conv *field)
{
	char	*output;

	field->str_size = (field->fl_witdth > 2) ? field->fl_witdth : 2;
	if (!(output = ft_strnewb(field->str_size)))
		return (NULL);
	output[0] = (c >> 6) + 0xC0;
	output[1] = (c & 0x3F) + 0x80;
	ft_align_wchar(output, field);
	return (output);
}

char			*handler_3oct_char(wint_t c, t_conv *field)
{
	char	*output;

	field->str_size = (field->fl_witdth > 3) ? field->fl_witdth : 3;
	if (!(output = ft_strnewb(field->str_size)))
		return (NULL);
	output[0] = (c >> 12) + 0xE0;
	output[1] = ((c >> 6) & 0x3F) + 0x80;
	output[2] = (c & 0x3F) + 0x80;
	ft_align_wchar(output, field);
	return (output);
}

char			*handler_4oct_char(wint_t c, t_conv *field)
{
	char			*output;

	field->str_size = (field->fl_witdth > 4) ? field->fl_witdth : 4;
	if (!(output = ft_strnewb(field->str_size)))
		return (NULL);
	output[0] = (c >> 18) + 0xF0;
	output[1] = ((c >> 12) & 0x3F) + 0x80;
	output[2] = ((c >> 6) & 0x3F) + 0x80;
	output[3] = (c & 0x3F) + 0x80;
	ft_align_wchar(output, field);
	return (output);
}

char			*handle_output_wchar(t_conv *field, va_list ap)
{
	char	*output;
	wint_t	c;

	c = (wint_t)va_arg(ap, wint_t);
	if (c < 0 || (MB_CUR_MAX == 1 && c > 0xFF) || (c >= 0xD800 && c <= 0xDFFF))
		return (NULL);
	else if (c <= 0x7F || (MB_CUR_MAX == 1 && c <= 0xFF))
	{
		field->str_size = (field->fl_witdth > 1) ? field->fl_witdth : 1;
		if (!(output = ft_strnewb(field->str_size)))
			return (NULL);
		output[0] = (char)c;
		ft_align_wchar(output, field);
	}
	else if (c <= 0x7FF)
		output = handler_2oct_char(c, field);
	else if (c <= 0xFFFF)
		output = handler_3oct_char(c, field);
	else if (c <= 0x10FFFF)
		output = handler_4oct_char(c, field);
	else
		return (NULL);
	return (output);
}
