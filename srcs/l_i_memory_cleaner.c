/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l-i_memory_cleaner.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 11:27:25 by klebon            #+#    #+#             */
/*   Updated: 2019/03/05 16:51:29 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_vertex(t_vertex **vtx)
{
	t_vertex	*todel;
	t_vertex	*tmp;

	tmp = *vtx;
	while (tmp)
	{
		todel = tmp;
		tmp = tmp->next;
		ft_strdel(&(todel->name));
		free(todel);
		todel = NULL;
	}
	*vtx = NULL;
}

void	delete_input(t_input **input)
{
	t_input	*todel;
	t_input	*tmp;

	tmp = *input;
	while (tmp)
	{
		todel = tmp;
		tmp = tmp->next;
		ft_strdel(&(todel->line));
		free(todel);
		todel = NULL;
	}
	input = NULL;
}

void	delete_path_tab(t_path_tab ***p)
{
	t_path_tab	*todel;
	int			i;

	i = -1;
	while ((*p)[++i])
	{
		while ((*p)[i])
		{
			todel = (*p)[i];
			(*p)[i] = (*p)[i]->next;
			free(todel);
			todel = NULL;
		}
		todel = (*p)[i];
		free(todel);
		todel = NULL;
	}
	free(*p);
	*p = NULL;
}

void	delete_adjacency_tab(t_adjacency ***tab)
{
	int			i;
	t_adjacency	*tmp;
	t_adjacency	*todel;

	i = -1;
	while (tab && *tab && (*tab)[++i])
	{
		tmp = (*tab)[i];
		while (tmp)
		{
			todel = tmp;
			tmp = tmp->next;
			free(todel);
			todel = NULL;
		}
		(*tab)[i] = NULL;
	}
	if (i != -1)
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
	}
	free(*tab);
	*tab = NULL;
}

void	clean_memory(t_adjmatrix **mat, t_vertex **vtx)
{
	delete_vertex(vtx);
	delete_input(&((*mat)->input));
	delete_adjacency_tab(&((*mat)->tab));
	free((*mat)->visited);
	(*mat)->visited = NULL;
	free((*mat)->old_visited);
	(*mat)->old_visited = NULL;
	free(*mat);
	*mat = NULL;
}
