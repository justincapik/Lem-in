/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_i_parse_mat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:40:53 by klebon            #+#    #+#             */
/*   Updated: 2019/03/09 13:49:50 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_bool	test_start_end(t_adjmatrix *mat)
{
	if (mat->start == -1 || mat->end == -1 || mat->tab[mat->start]->next == NULL
			|| mat->tab[mat->end]->next == NULL)
		return (false);
	return (true);
}

static t_bool	mat_split(t_vertex *vtx, t_adjmatrix **mat, char *line)
{
	char		**tab;
	t_vertex	*s;
	t_vertex	*t;

	if (!(tab = ft_strsplit(line, '-')))
		return (false);
	if (ft_strtablen(tab) != 2 || (s = get_vertex(vtx, tab[0])) == NULL
			|| (t = get_vertex(vtx, tab[1])) == NULL
			|| add_adjacency(&(((*mat)->tab)[s->id]), t->id)
			|| add_adjacency(&(((*mat)->tab)[t->id]), s->id))
	{
		ft_strtabdel(&tab);
		return (error);
	}
	ft_strtabdel(&tab);
	return (true);
}

static t_bool	init_adjacency_tab(t_adjmatrix **mat, t_vertex *vtx)
{
	int			len;
	int			i;

	len = get_last_vertex(vtx)->id + 2;
	if (!((*mat)->tab = (t_adjacency **)malloc(sizeof(t_adjacency *) * len)))
		return (false);
	if (!((*mat)->visited = (t_bool *)malloc(sizeof(t_bool *) * len)))
		return (false);
	if (!((*mat)->old_visited = (t_bool *)malloc(sizeof(t_bool *) * len)))
		return (false);
	((*mat)->tab)[len - 1] = NULL;
	i = 0;
	while (i < (len - 1))
	{
		if (!((*mat)->tab[i] = (t_adjacency *)malloc(sizeof(t_adjacency))))
			return (false);
		init_adjacency_tab_helper(mat, i);
		++i;
	}
	(*mat)->visited[i] = neg;
	(*mat)->old_visited[i] = neg;
	return (true);
}

t_bool			parse_mat(t_vertex *vtx, t_adjmatrix **mat, char **line)
{
	int		ret;

	if (!(**line))
		return (error);
	if (init_adjacency_tab(mat, vtx) || mat_split(vtx, mat, *line))
		return (false);
	while ((ret = get_next_line(0, line)))
	{
		if (ret == -1 || add_input_line(&((*mat)->input), line))
			return (false);
		if (!(**line))
			return (error);
		if ((*line)[0] == '#')
			continue ;
		else if ((*line)[0] != '#' && mat_split(vtx, mat, *line))
			return (false);
	}
	if (test_start_end(*mat) == false)
		return (false);
	return (true);
}
