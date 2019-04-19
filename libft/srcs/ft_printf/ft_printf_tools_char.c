/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 08:51:48 by klebon            #+#    #+#             */
/*   Updated: 2018/10/30 12:35:10 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*handle_output_char(t_conv *field, va_list ap)
{
	char			*output;
	unsigned char	c;

	if (field->fl_type == percent)
		c = '%';
	else
		c = (unsigned char)va_arg(ap, int);
	field->str_size = (field->fl_witdth > 1) ? field->fl_witdth : 1;
	if (!(output = ft_strnewb(field->str_size)))
		return (NULL);
	output[0] = c;
	ft_align_wchar(output, field);
	return (output);
}
