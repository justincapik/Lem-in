/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l-i_texture_placing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:34:33 by jucapik           #+#    #+#             */
/*   Updated: 2019/03/08 14:09:26 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_vertex		*get_vertex_con(int id, t_vertex *base)
{
	while (base != NULL && base->id != id)
		base = base->next;
	return (base);
}

static void			draw_connections(t_img *img,
		t_adjmatrix *mat, t_vertex *base)
{
	t_pixpos	p0;
	t_pixpos	p1;
	t_vertex	*oth;
	t_vertex	*vtx;
	t_adjacency	*con;

	vtx = base;
	while (vtx != NULL)
	{
		con = mat->tab[vtx->id]->next;
		while (con != NULL)
		{
			p0.x = (int)(vtx->coord_x * img->width_multi) + img->tex_size / 2;
			p0.y = (int)(vtx->coord_y * img->height_multi) + img->tex_size / 2;
			oth = get_vertex_con(con->id, base);
			if (oth == NULL)
				return ;
			p1.x = (int)(oth->coord_x * img->width_multi) + img->tex_size / 2;
			p1.y = (int)(oth->coord_y * img->height_multi) + img->tex_size / 2;
			draw_line(img, p0, p1);
			con = con->next;
		}
		vtx = vtx->next;
	}
}

static void			get_size_multi(t_img *img, t_vertex *vertex)
{
	int		x_max;
	int		y_max;

	x_max = -1;
	y_max = -1;
	while (vertex != NULL)
	{
		if (vertex->coord_x > x_max)
			x_max = vertex->coord_x;
		if (vertex->coord_y > y_max)
			y_max = vertex->coord_y;
		vertex = vertex->next;
	}
	img->height_multi = (((double)img->height) / ((double)y_max * 1.2));
	img->width_multi = (((double)img->width) / ((double)x_max * 1.2));
}

static t_bool		put_tex(t_img *img, t_vertex *vtx, SDL_Texture *tex)
{
	SDL_Rect rct;

	rct.x = (int)(vtx->coord_x * img->width_multi);
	rct.y = (int)(vtx->coord_y * img->height_multi);
	rct.h = img->tex_size;
	if (tex == img->mansion_tex)
		rct.w = (int)(img->tex_size * 2);
	else
		rct.w = img->tex_size;
	SDL_RenderCopy(img->renderer, tex, NULL, &rct);
	return (true);
}

t_bool				initial_placing(t_adjmatrix *mat,
		t_img *img, t_vertex *vertex)
{
	get_size_multi(img, vertex);
	SDL_RenderCopy(img->renderer, img->backround_tex, NULL, NULL);
	draw_connections(img, mat, vertex);
	while (vertex != NULL)
	{
		if (vertex->id == mat->start)
			put_tex(img, vertex, img->ruin_tex);
		else if (vertex->id == mat->end)
			put_tex(img, vertex, img->mansion_tex);
		else
			put_tex(img, vertex, img->house_tex);
		vertex = vertex->next;
	}
	return (1);
}
