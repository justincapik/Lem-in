/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 12:00:11 by klebon            #+#    #+#             */
/*   Updated: 2018/04/07 14:56:02 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	i = -1;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (++i < (size + 1))
		str[i] = '\0';
	return (str);
}
