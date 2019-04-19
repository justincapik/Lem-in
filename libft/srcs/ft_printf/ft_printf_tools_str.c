/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 09:05:22 by klebon            #+#    #+#             */
/*   Updated: 2018/05/25 18:57:58 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_align_wstr(char *str, t_conv *field)
{
	int		i;
	int		len;

	i = 0;
	if (field->fl_witdth >= 1)
	{
		if (field->fl_minus)
		{
			while (str[i])
				i++;
			while (i < field->str_size)
				str[i++] = ' ';
		}
		else
		{
			len = (int)ft_strlen(str);
			ft_memmove(str + (field->str_size - len), str, len);
			while (i < (field->str_size - len))
			{
				str[i] = ' ';
				i++;
			}
		}
	}
}

char	*handle_output_str(t_conv *field, va_list ap)
{
	char		*output;
	int			len;
	const char	*str;

	str = va_arg(ap, const char *);
	if (str == NULL)
		str = "(null)";
	len = (int)ft_strlen(str);
	if (field->fl_prec != -1)
		len = (len > field->fl_prec) ? field->fl_prec : len;
	field->str_size = (field->fl_witdth > len) ? field->fl_witdth : len;
	if (!(output = ft_strnewb(field->str_size)))
		return (NULL);
	if (field->fl_prec == -1)
		ft_strcpy_s(output, str);
	else
		ft_strncpy_s(output, str, field->fl_prec);
	ft_align_wstr(output, field);
	return (output);
}
