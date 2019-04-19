/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l-i_getter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:08:50 by klebon            #+#    #+#             */
/*   Updated: 2019/02/16 23:01:26 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_vertex	*get_last_vertex(t_vertex *vtx)
{
	t_vertex	*tmp;

	tmp = vtx;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_vertex	*get_vertex(t_vertex *vtx, char *name)
{
	t_vertex	*tmp;

	tmp = vtx;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
