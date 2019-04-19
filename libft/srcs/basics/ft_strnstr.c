/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 20:31:58 by klebon            #+#    #+#             */
/*   Updated: 2018/04/03 19:28:22 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t	i;
	size_t	nlen;

	i = 0;
	if (!(nlen = ft_strlen(needle)))
		return ((char *)str);
	while (str[i] && (i + nlen) <= len)
	{
		if (!ft_memcmp(str + i, needle, nlen))
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
