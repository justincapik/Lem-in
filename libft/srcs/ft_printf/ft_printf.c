/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 22:27:58 by klebon            #+#    #+#             */
/*   Updated: 2018/11/05 08:50:37 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_handler_tab(char *(*f[14])(t_conv *, va_list))
{
	f[d] = &handle_output_i_d;
	f[D] = &handle_output_i_d;
	f[i] = &handle_output_i_d;
	f[x] = &handle_output_hexa;
	f[X] = &handle_output_hexa;
	f[p] = &handle_output_hexa;
	f[o] = &handle_output_oct;
	f[O] = &handle_output_oct;
	f[u] = handle_output_u;
	f[U] = handle_output_u;
	f[c] = &handle_output_char;
	f[C] = &handle_output_wchar;
	f[s] = &handle_output_str;
	f[S] = &handle_output_wstr;
	f[percent] = &handle_output_char;
}

void	clean_mem(t_conv *field, va_list ap)
{
	free(field);
	va_end(ap);
}

int		handle_conv(const char **str, t_conv *field, va_list ap, int *nb_print)
{
	char		*(*handler[15])(t_conv *, va_list);

	init_handler_tab(handler);
	(*str)++;
	if (check_fields(str, ap, field))
	{
		if (!(field->str = handler[field->fl_type](field, ap)))
		{
			clean_mem(field, ap);
			return (0);
		}
		write(1, field->str, field->str_size);
		*nb_print += field->str_size;
		free(field->str);
	}
	else
	{
		clean_mem(field, ap);
		return (0);
	}
	return (1);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	const char	*str;
	int			nb_print_chars;
	t_conv		*field;

	if (!(field = (t_conv *)malloc(sizeof(t_conv))))
		return (-1);
	va_start(ap, format);
	str = format;
	nb_print_chars = 0;
	while (str && *str)
	{
		if (*str != '%')
		{
			write(1, str, 1);
			++nb_print_chars;
		}
		else if (!(handle_conv(&str, field, ap, &nb_print_chars)))
			return (-1);
		++str;
	}
	clean_mem(field, ap);
	return (nb_print_chars);
}
