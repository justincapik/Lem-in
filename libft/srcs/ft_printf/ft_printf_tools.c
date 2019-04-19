/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 21:49:45 by klebon            #+#    #+#             */
/*   Updated: 2018/09/16 21:26:10 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			init_struct_conv(t_conv *field)
{
	field->fl_minus = 0;
	field->fl_plus = 0;
	field->fl_zero = 0;
	field->fl_hashtag = 0;
	field->fl_space = 0;
	field->fl_witdth = 0;
	field->fl_prec = -1;
	field->fl_size = -1;
	field->fl_type = -1;
	field->str = NULL;
	field->str_size = 0;
}

char			*ft_strnewb(size_t size)
{
	size_t	i;
	char	*str;

	i = -1;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (++i < (size + 1))
		str[i] = '\0';
	return (str);
}
