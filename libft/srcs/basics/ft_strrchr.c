/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:07:41 by klebon            #+#    #+#             */
/*   Updated: 2018/04/06 17:40:47 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*search;

	search = NULL;
	while (*s)
	{
		if (*s == (char)c)
			search = (char *)s;
		s++;
	}
	if (*s == (char)c)
		search = (char *)s;
	return (search);
}
