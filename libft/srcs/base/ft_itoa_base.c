/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 13:37:31 by klebon            #+#    #+#             */
/*   Updated: 2018/04/08 14:59:19 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int value, char *base_to)
{
	unsigned int	n;
	int				size;
	char			*str;
	int				neg;
	int				base_len;

	size = (value < 0) ? 2 : 1;
	base_len = ft_strlen(base_to);
	if (value == 0)
		return ("0");
	neg = (value < 0) ? -1 : 1;
	n = value * neg;
	while (value /= base_len)
		size++;
	if (!(str = ft_strnew(size)))
		return (NULL);
	while (size--)
	{
		str[size] = base_to[n % base_len];
		n /= base_len;
	}
	if (neg == -1)
		*--str = '-';
	return (str);
}
