/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrtotab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:18:41 by klebon            #+#    #+#             */
/*   Updated: 2018/11/27 19:35:05 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lststrtotab(t_list *alst)
{
	char	**tab;
	t_list	*tmp;
	int		i;

	tab = NULL;
	if (alst)
	{
		tmp = alst;
		i = -1;
		if (!(tab = (char **)malloc(sizeof(char *) * (ft_lstlen(alst) + 1))))
			return (NULL);
		while (tmp)
		{
			if (!(tab[++i] = ft_strdup(tmp->content)))
			{
				ft_strtabdel(&tab);
				return (NULL);
			}
			tmp = tmp->next;
		}
		tab[++i] = NULL;
	}
	return (tab);
}
