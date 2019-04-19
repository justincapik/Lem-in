/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_lenght.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:40:34 by klebon            #+#    #+#             */
/*   Updated: 2018/10/01 15:41:28 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned int	ft_bin_size(unsigned int nb)
{
	unsigned int	n;
	unsigned int	size;

	n = nb;
	size = 1;
	while (n /= 2)
		size++;
	return (size);
}

int				ft_wstrlen(const wint_t *str)
{
	int				i;
	int				len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] < 0 || (MB_CUR_MAX == 1 && str[i] > 0xFF)
				|| (str[i] >= 0xD800 && str[i] <= 0xDFFF) || str[i] > 0x10FFFF)
			return (-1);
		else if (str[i] <= 0x7F || (MB_CUR_MAX == 1 && str[i] <= 0xFF))
			len += 1;
		else if (str[i] <= 0x7FF)
			len += 2;
		else if (str[i] <= 0xFFFF)
			len += 3;
		else if (str[i] <= 0x10FFFF)
			len += 4;
		++i;
	}
	return (len);
}
