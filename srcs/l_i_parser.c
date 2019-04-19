/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_i_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 11:41:44 by klebon            #+#    #+#             */
/*   Updated: 2019/03/09 13:33:26 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_bool	test_vertex(char *line, t_vertex **vtx)
{
	char	**tab;

	if (!(tab = ft_strsplit(line, ' ')))
		return (false);
	if (ft_strtablen(tab) != 3)
	{
		ft_strtabdel(&tab);
		return (error);
	}
	else if (tab[0][0] == 'L' || ft_strchr(tab[0], '-')
		|| add_vertex(vtx, tab[0], ft_atoi(tab[1]), ft_atoi(tab[2])))
	{
		ft_strtabdel(&tab);
		return (false);
	}
	ft_strtabdel(&tab);
	return (true);
}

static t_bool	parse_vertex(t_vertex **vtx, t_adjmatrix *mat, char *line)
{
	static int	start = 0;
	static int	end = 0;
	t_bool		ret;

	if (!ft_strcmp(line, "##start"))
		++start;
	else if (!ft_strcmp(line, "##end"))
		++end;
	else if (line[0] == '#')
		return (true);
	else if (line[0] != '#' && ft_strchr(line, ' '))
	{
		if ((ret = test_vertex(line, vtx)))
			return (ret);
		if (start == 1 && ++start)
			mat->start = get_last_vertex(*vtx)->id;
		if (end == 1 && ++end)
			mat->end = get_last_vertex(*vtx)->id;
	}
	else if (line[0] != '#')
		return (neg);
	return (true);
}

static t_bool	parse_ants(t_adjmatrix *mat)
{
	int		ret;
	char	*line;

	line = NULL;
	if ((ret = get_next_line(0, &line)))
	{
		if (ret == -1 || add_input_line(&(mat->input), &line))
			return (false);
		if (line[0] != '\0' && (ft_str_is_numeric(line)
			|| (line[0] == '+' && ft_str_is_numeric(line + 1))))
			mat->ants = ft_atoi(line);
		else
			return (false);
	}
	return ((mat->ants == 0) ? false : true);
}

t_bool			parser(t_vertex **vtx, t_adjmatrix **mat)
{
	int		ret;
	t_bool	flag;
	char	*line;

	line = NULL;
	if ((flag = parse_ants(*mat)))
		return (flag);
	while ((ret = get_next_line(0, &line)))
	{
		if (ret == -1 || add_input_line(&((*mat)->input), &line))
			return (false);
		if (flag != neg && ((flag = parse_vertex(vtx, *mat, line))
			&& flag != neg))
			return (flag);
		if (flag == neg)
			break ;
	}
	return ((ret == 0) ? false : parse_mat(*vtx, mat, &line));
}
