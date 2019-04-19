/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_i_path_tab_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:09:44 by klebon            #+#    #+#             */
/*   Updated: 2019/03/09 11:06:57 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			path_size(t_path_tab *paths)
{
	int			len;
	t_path_tab	*tmp;

	len = 0;
	tmp = paths;
	while (tmp)
	{
		len += tmp->size;
		tmp = tmp->next;
	}
	return (len);
}

int			get_room(t_path_tab *paths, int room)
{
	int			n;
	t_path_tab	*tmp;

	tmp = paths;
	n = room;
	if (n < PATH_BUFF)
		return ((tmp->tab)[n]);
	else
	{
		while (n >= PATH_BUFF)
		{
			n -= PATH_BUFF;
			tmp = tmp->next;
		}
		return ((tmp->tab)[n]);
	}
}
