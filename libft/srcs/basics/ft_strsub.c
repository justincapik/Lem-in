/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 21:14:07 by klebon            #+#    #+#             */
/*   Updated: 2018/04/07 15:40:45 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*snew;
	size_t	i;

	i = 0;
	if (!s || !(snew = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		snew[i] = s[start + i];
		i++;
	}
	return (snew);
}
