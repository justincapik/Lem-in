/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 22:02:03 by klebon            #+#    #+#             */
/*   Updated: 2018/04/07 16:23:51 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((const unsigned char *)src)[i] != (unsigned char)c)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	if (i < n && (((const unsigned char *)src)[i] == (unsigned char)c))
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		return (dest + i + 1);
	}
	return (NULL);
}
