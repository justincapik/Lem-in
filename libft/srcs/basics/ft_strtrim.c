/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 22:06:42 by klebon            #+#    #+#             */
/*   Updated: 2018/04/07 15:45:31 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	size;
	size_t	i;
	size_t	start;

	if (!s)
		return (NULL);
	i = 0;
	size = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	start = i;
	if (!s[i])
		return (ft_strnew(1));
	while (s[i])
	{
		size++;
		i++;
	}
	i--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i--;
		size--;
	}
	return (ft_strsub(s, start, size));
}
