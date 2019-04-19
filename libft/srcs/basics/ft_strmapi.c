/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 13:02:37 by klebon            #+#    #+#             */
/*   Updated: 2018/04/07 15:35:01 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*snew;

	if (s)
	{
		i = 0;
		if (!(snew = ft_strnew(ft_strlen(s))))
			return (NULL);
		while (s[i])
		{
			snew[i] = f(i, s[i]);
			i++;
		}
		return (snew);
	}
	return (NULL);
}
