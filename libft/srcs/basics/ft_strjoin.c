/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 21:39:20 by klebon            #+#    #+#             */
/*   Updated: 2018/04/07 15:43:06 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*snew;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(snew = ft_strnew(size)))
		return (NULL);
	while (*s1)
	{
		snew[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		snew[i++] = *s2;
		s2++;
	}
	snew[i] = '\0';
	return (snew);
}
