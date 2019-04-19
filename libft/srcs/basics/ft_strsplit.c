/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:39:38 by klebon            #+#    #+#             */
/*   Updated: 2019/02/13 15:38:32 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbwords(char const *s, char c)
{
	size_t	words;
	int		i;

	i = 0;
	words = 0;
	while (s[i] && s[i] == c)
		++i;
	while (s[i])
	{
		if (s[i] == c && i != 0)
		{
			++words;
			while (s[i] && s[i] == c)
				++i;
		}
		else
			++i;
	}
	if (s[i] == '\0' && s[i - 1] != c)
		++words;
	return (words);
}

static int		ft_wordsalloc(char **tab, char const *s, char c)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	start = 0;
	j = -1;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			start = ++i;
		if (s[i] && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			if (!(tab[++j] = ft_strsub(s, start, i - start + 1)))
			{
				ft_strtabdel(&tab);
				return (2);
			}
		}
		if (s[i])
			++i;
	}
	tab[++j] = NULL;
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	nbwords;
	char	**tab;

	if (!s)
		return (NULL);
	nbwords = ft_nbwords(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (nbwords + 1))))
		return (NULL);
	if (ft_wordsalloc(tab, s, c))
		return (NULL);
	return (tab);
}
