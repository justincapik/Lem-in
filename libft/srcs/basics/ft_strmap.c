/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 12:50:07 by klebon            #+#    #+#             */
/*   Updated: 2018/04/07 15:32:52 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*snew;

	if (s)
	{
		i = -1;
		if (!(snew = ft_strnew(ft_strlen(s))))
			return (NULL);
		while (s[++i])
			snew[i] = f(s[i]);
		return (snew);
	}
	return (NULL);
}
