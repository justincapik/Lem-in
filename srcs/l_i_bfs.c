/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l-i_bfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <jucapik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:18:17 by jucapik           #+#    #+#             */
/*   Updated: 2019/03/08 15:03:27 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			clean_vis(t_bool *vis, t_bool *old_vis)
{
	int		i;

	i = 0;
	while (vis[i] != neg)
	{
		old_vis[i] = false;
		vis[i] = false;
		++i;
	}
}

static t_adjacency	*go_to_end(t_adjacency *con, t_adjmatrix *mat)
{
	t_adjacency	*og_con;

	og_con = con;
	if (con == NULL)
		return (NULL);
	while (con->next != NULL)
		con = con->next;
	while (con->next_in_order != -1)
	{
		if (og_con->id == con->next_in_order)
			return (NULL);
		con = mat->tab[con->next_in_order]->next;
		while (con->next != NULL)
			con = con->next;
	}
	return (con);
}

static t_adjacency	*use_only_two(t_adjmatrix *mat, t_adjacency *con, int base)
{
	t_adjacency *last;

	while (con != NULL && con->weight != 2)
		con = con->next;
	if (con == NULL)
		return (NULL);
	if (con->weight > 0 && mat->visited[con->id] == false
			&& (last = go_to_end(con, mat)) != NULL)
	{
		last->next_in_order = con->id;
		update_father_id(mat, con, base);
	}
	while (con->next != NULL)
		con = con->next;
	return (con);
}

static t_adjacency	*use_all(t_adjacency *con, t_adjmatrix *mat, int base)
{
	t_adjacency *last;

	while (con->next != NULL)
	{
		if (con->weight > 0 && mat->visited[con->id] == false
				&& !(mat->old_visited[base] == true
					&& mat->old_visited[con->id] == true
					&& con->weight == 1)
				&& (last = go_to_end(con, mat)) != NULL)
		{
			last->next_in_order = con->id;
			update_father_id(mat, con, base);
		}
		con = con->next;
	}
	if (con->weight > 0 && mat->visited[con->id] == false
			&& !(mat->old_visited[base] == true
				&& mat->old_visited[con->id] == true
				&& con->weight == 1)
			&& (last = go_to_end(con, mat)) != NULL)
	{
		last->next_in_order = con->id;
		update_father_id(mat, con, base);
	}
	return (con);
}

t_bool				bfs(t_adjmatrix *mat, int start, int end)
{
	t_adjacency	*con;
	t_bool		old_overlap;
	int			base;

	base = start;
	con = mat->tab[base]->next;
	while (base != end)
	{
		old_overlap = false;
		mat->visited[base] = true;
		if (mat->old_visited[base] == true
				&& mat->old_visited[con->father_id] == false)
			con = use_only_two(mat, con, base);
		else
			con = use_all(con, mat, base);
		if (con->next_in_order == -1)
			return (false);
		base = con->next_in_order;
		con->next_in_order = -1;
		con = mat->tab[base]->next;
	}
	clean_next_in_order(mat, con);
	clean_vis(mat->visited, mat->old_visited);
	update_adjmatrix_path(mat);
	return (true);
}
