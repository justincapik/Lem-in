/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_i_memory_allocation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 10:44:59 by klebon            #+#    #+#             */
/*   Updated: 2019/03/08 19:16:24 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool		add_vertex(t_vertex **vtx, char *name, int x, int y)
{
	t_vertex	*new;
	t_vertex	*tmp;

	if (!(new = (t_vertex *)malloc(sizeof(t_vertex))))
		return (false);
	if (!(new->name = ft_strdup(name)))
		return (false);
	new->coord_x = x;
	new->coord_y = y;
	new->next = NULL;
	if (*vtx == NULL)
	{
		new->id = 0;
		*vtx = new;
	}
	else
	{
		tmp = *vtx;
		while (tmp->next)
			tmp = tmp->next;
		new->id = tmp->id + 1;
		tmp->next = new;
	}
	return (true);
}

t_bool		init_adjmatrix(t_adjmatrix **mat)
{
	if (!((*mat) = (t_adjmatrix *)malloc(sizeof(t_adjmatrix))))
		return (false);
	(*mat)->input = NULL;
	(*mat)->tab = NULL;
	(*mat)->visited = NULL;
	(*mat)->old_visited = NULL;
	(*mat)->start = -1;
	(*mat)->end = -1;
	(*mat)->opt_paths = false;
	(*mat)->opt_nblines = false;
	return (true);
}

t_bool		add_adjacency(t_adjacency **adj, int id)
{
	t_adjacency	*tmp;
	t_adjacency	*new;

	tmp = *adj;
	while (tmp && tmp->next)
	{
		if (tmp->id == id)
			return (true);
		tmp = tmp->next;
	}
	if (tmp && tmp->id == id)
		return (true);
	if (!(new = (t_adjacency *)malloc(sizeof(t_adjacency))))
		return (false);
	new->id = id;
	new->weight = 1;
	new->father_id = -1;
	new->next_in_order = -1;
	new->next = NULL;
	if (tmp)
		tmp->next = new;
	else
		*adj = new;
	return (true);
}

t_bool		add_input_line(t_input **input, char **str)
{
	t_input	*new;
	t_input	*tmp;

	if (!(new = (t_input *)malloc(sizeof(t_input))))
		return (false);
	new->line = *str;
	new->next = NULL;
	if (*input == NULL)
		*input = new;
	else
	{
		tmp = *input;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (true);
}
