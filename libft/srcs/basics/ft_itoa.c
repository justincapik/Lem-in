/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 22:41:19 by klebon            #+#    #+#             */
/*   Updated: 2018/04/06 17:56:06 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	size;
	long	nb;
	long	isneg;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	isneg = (n < 0) ? -1 : 1;
	nb = n * isneg;
	size = (n < 0) ? 2 : 1;
	while (nb /= 10)
		size++;
	if (!(str = ft_strnew(size)))
		return (NULL);
	nb = n * isneg;
	while (size--)
	{
		str[size] = nb % 10 + '0';
		nb /= 10;
	}
	if (isneg == -1)
		str[0] = '-';
	return (str);
}
