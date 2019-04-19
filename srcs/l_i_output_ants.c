/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_i_output_ants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 13:03:38 by klebon            #+#    #+#             */
/*   Updated: 2019/03/09 09:53:34 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool		init_output_str(t_vertex *vtx, char ***out)
{
	int			len;
	int			i;
	t_vertex	*tmp;

	len = get_last_vertex(vtx)->id + 2;
	if (!(*out = (char **)malloc(sizeof(char *) * len)))
		return (false);
	i = 0;
	tmp = vtx;
	while (tmp)
	{
		if (!((*out)[i] = ft_strdup(tmp->name)))
			return (false);
		tmp = tmp->next;
		++i;
	}
	(*out)[i] = NULL;
	return (true);
}

t_bool		insert_ants(t_ants **ants, t_path_tab **path)
{
	int			i;
	static int	number = 0;
	t_ants		*new;
	t_ants		*tmp;

	i = -1;
	while (path[++i] && (path[i]->nb_ants)-- > 0)
	{
		if (!(new = (t_ants *)malloc(sizeof(t_ants))))
			return (false);
		insert_ants_helper(new, path, i, &number);
		if (*ants == NULL)
			*ants = new;
		else
		{
			tmp = *ants;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
	return (true);
}

void		print_ants(t_ants **ants, char **out, int end)
{
	t_ants	*todel;
	t_ants	*tmp;

	while (*ants && get_room((*ants)->path, (*ants)->room) == end)
	{
		todel = *ants;
		*ants = (*ants)->next;
		del_ants(&todel);
	}
	tmp = *ants;
	write(1, "\n", 1);
	while (tmp)
	{
		++(tmp->room);
		if (tmp != *ants)
			write(1, " ", 1);
		ft_printf("L%d-%s", tmp->number, out[get_room(tmp->path, tmp->room)]);
		while (tmp->next && get_room(tmp->next->path, tmp->next->room) == end)
		{
			todel = tmp->next;
			tmp->next = tmp->next->next;
			del_ants(&todel);
		}
		tmp = tmp->next;
	}
}

t_bool		output_ants(t_path_tab **paths, t_vertex *vtx, t_adjmatrix *mat)
{
	char		**out;
	t_ants		*ants;
	int			i;

	ants = NULL;
	i = 0;
	if (!init_output_str(vtx, &out))
	{
		while (i == 0 || ants)
		{
			if (insert_ants(&ants, paths))
			{
				del_all_ants(&ants);
				ft_strtabdel(&out);
				return (false);
			}
			if (mat->img != NULL)
				draw_ants(mat, ants, &(mat->img), vtx);
			print_ants(&ants, out, mat->end);
			++i;
		}
	}
	print_opts(mat, paths, i - 1, out);
	ft_strtabdel(&out);
	return (true);
}

t_bool		output_all_ants(t_path_tab **paths, t_vertex *vtx, t_adjmatrix *mat)
{
	char		**out;
	t_ants		*ants;
	int			nb_ants;

	ants = NULL;
	nb_ants = mat->ants;
	if (!init_output_str(vtx, &out))
	{
		while (nb_ants--)
		{
			if (insert_ants(&ants, paths))
			{
				del_all_ants(&ants);
				ft_strtabdel(&out);
				return (false);
			}
		}
		if (mat->img != NULL)
			draw_ants(mat, ants, &(mat->img), vtx);
		print_ants(&ants, out, mat->end);
		print_ants(&ants, out, mat->end);
	}
	print_opts(mat, paths, 1, out);
	ft_strtabdel(&out);
	return (true);
}
