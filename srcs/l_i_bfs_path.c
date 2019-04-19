/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l-i_bfs_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <jucapik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:26:27 by jucapik           #+#    #+#             */
/*   Updated: 2019/03/08 15:01:51 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				clean_next_in_order(t_adjmatrix *mat, t_adjacency *con)
{
	t_adjacency *tmp;

	while (con->next != NULL)
		con = con->next;
	while (con->next_in_order != -1)
	{
		tmp = con;
		con = mat->tab[con->next_in_order]->next;
		tmp->next_in_order = -1;
		while (con->next != NULL)
			con = con->next;
	}
}

t_bool				update_father_id(t_adjmatrix *mat,
		t_adjacency *con, int base)
{
	con = mat->tab[con->id];
	while (con != NULL)
	{
		con->father_id = base;
		con = con->next;
	}
	return (true);
}

static t_adjacency	*get_right_adjacency(t_adjacency *node, int id)
{
	while (node != NULL && node->id != id)
		node = node->next;
	return (node);
}

static t_bool		change_connection(t_adjmatrix *mat, int n1, int n2, int ch)
{
	t_adjacency *node;

	if (n1 == -1 || n2 == -1)
		return (false);
	node = get_right_adjacency(mat->tab[n1], n2);
	if (node == NULL || (node->weight <= 0 && ch == -1)
			|| (node->weight >= 2 && ch == 1))
		return (false);
	node->weight += ch;
	return (true);
}

t_bool				update_adjmatrix_path(t_adjmatrix *mat)
{
	int		cur;
	int		father;

	cur = mat->end;
	while (cur != mat->start)
	{
		father = mat->tab[cur]->father_id;
		if (change_connection(mat, cur, father, 1) == false
				|| change_connection(mat, father, cur, -1) == false)
			return (false);
		cur = father;
	}
	return (true);
}
