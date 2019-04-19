/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 14:48:47 by klebon            #+#    #+#             */
/*   Updated: 2018/04/28 14:48:58 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_realloc(char *ptr, size_t size)
{
	char	*tmp;

	if (!(tmp = ft_strnew(size)))
		return (NULL);
	if (ptr)
	{
		ft_strcpy(tmp, ptr);
		free(ptr);
	}
	return (tmp);
}
