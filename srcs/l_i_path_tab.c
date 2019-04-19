/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l-i_path_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <jucapik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:32:57 by jucapik           #+#    #+#             */
/*   Updated: 2019/03/09 11:29:20 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_path_tab	*create_path_tab(void)
{
	t_path_tab	*path;

	if (!(path = (t_path_tab *)malloc(sizeof(t_path_tab))))
		return (NULL);
	path->next = NULL;
	return (path);
}

static t_adjacency	*get_path_place(t_adjmatrix *mat, int id, int i)
{
	int			count;
	t_adjacency	*node;

	count = 0;
	node = mat->tab[id];
	while (node != NULL)
	{
		if (node->weight == 0)
		{
			if (count == i)
				return (node);
			++count;
		}
		node = node->next;
	}
	return (NULL);
}

static t_path_tab	*get_path(int *j, t_path_tab *path,
		t_adjmatrix *mat, t_adjacency *node)
{
	path->tab[0] = mat->start;
	mat->old_visited[node->id] = true;
	while (node->id != mat->end)
	{
		if (*j >= PATH_BUFF)
		{
			*j = 0;
			path->next = create_path_tab();
			path->size = PATH_BUFF;
			path = path->next;
		}
		path->tab[(*j)++] = node->id;
		if ((node = get_path_place(mat, node->id, 0)) == NULL)
			return (NULL);
		mat->old_visited[node->id] = true;
	}
	return (path);
}

static t_path_tab	*find_path(t_adjmatrix *mat, int i)
{
	int			j;
	t_adjacency *node;
	t_path_tab	*base;
	t_path_tab	*path;

	path = create_path_tab();
	base = path;
	if (!(node = get_path_place(mat, mat->start, i)))
		return (NULL);
	j = 1;
	if ((path = get_path(&j, path, mat, node)) == NULL)
		return (NULL);
	if (j >= PATH_BUFF)
	{
		j = 0;
		path->next = create_path_tab();
		path->size = PATH_BUFF;
		path = path->next;
		path->size = 1;
	}
	else
		path->size = j + 1;
	path->tab[j] = mat->end;
	return (base);
}

t_path_tab			**get_path_tab(t_adjmatrix *mat, int size)
{
	t_path_tab	**tab;
	int			i;

	if (!(tab = (t_path_tab **)malloc(sizeof(t_path_tab *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if ((tab[i] = find_path(mat, i)) == NULL)
			return (NULL);
		tab[i]->nb_ants = 0;
		++i;
	}
	tab[i] = NULL;
	sort_paths(tab);
	mat->old_visited[mat->end] = false;
	mat->old_visited[mat->start] = false;
	return (tab);
}
