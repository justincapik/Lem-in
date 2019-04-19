/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:23:30 by klebon            #+#    #+#             */
/*   Updated: 2018/04/06 17:26:17 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	n;
	int	isneg;

	n = 0;
	isneg = 1;
	while (*nptr == '\v' || *nptr == '\t' || *nptr == '\f' || *nptr == '\n'
			|| *nptr == '\r' || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
		isneg = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		n = n * 10 + *nptr - '0';
		nptr++;
	}
	return (isneg * n);
}
