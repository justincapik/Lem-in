/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 13:40:09 by klebon            #+#    #+#             */
/*   Updated: 2018/04/08 14:48:06 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(char *nbr, char *base_from)
{
	int j;
	int	size;
	int	neg;
	int	res;
	int	base_len;

	res = 0;
	size = 0;
	base_len = ft_strlen(base_from);
	if (!(size = ft_isinbase(nbr, base_from)))
		return (0);
	neg = (*nbr == '-') ? -1 : 1;
	if (*nbr == '-')
		nbr++;
	while (*nbr != '\0')
	{
		j = 0;
		while (*nbr != base_from[j])
			j++;
		res += j * ft_recursive_power(base_len, --size);
		nbr++;
	}
	return (neg * res);
}
