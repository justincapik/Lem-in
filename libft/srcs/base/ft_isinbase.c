/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinbase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 13:38:39 by klebon            #+#    #+#             */
/*   Updated: 2018/04/08 13:39:54 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isinbase(char *nbr, char *base_from)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	j = 0;
	while (nbr[++i] != '\0')
	{
		j = -1;
		flag = 0;
		while (base_from[++j] != '\0')
			if (nbr[i] == base_from[j])
				flag++;
		if (flag != 1)
			return (0);
	}
	return (i);
}
