/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:50:01 by klebon            #+#    #+#             */
/*   Updated: 2018/04/06 17:43:33 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	i;

	i = 0;
	dlen = ft_strlen(dest);
	if (dlen < size)
	{
		while (i < (size - dlen - 1) && src[i])
		{
			dest[dlen + i] = src[i];
			i++;
		}
		dest[dlen + i] = '\0';
		return (dlen + ft_strlen(src));
	}
	return (size + ft_strlen(src));
}
