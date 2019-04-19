/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_i_draw_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <jucapik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 11:19:44 by jucapik           #+#    #+#             */
/*   Updated: 2019/03/09 11:48:55 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		place_ants(t_img **img, int x, int y)
{
	SDL_Rect rct;

	rct.x = x;
	rct.y = y;
	rct.h = (*img)->tex_size;
	rct.w = (*img)->tex_size;
	SDL_RenderCopy((*img)->renderer, (*img)->ant_tex, NULL, &rct);
}

t_bool			get_pas(int frames, t_ants *ant, t_vertex *vtx,
		t_adjmatrix *mat)
{
	int tofind;

	tofind = (ant->room + 1 >= ant->path->size)
		? mat->end : ant->path->tab[ant->room + 1];
	while (vtx != NULL && vtx->id != tofind)
		vtx = vtx->next;
	if (vtx == NULL)
		return (error);
	ant->pasx = (int)(((vtx->coord_x * mat->img->width_multi) - ant->x)
			/ frames);
	ant->pasy = (int)(((vtx->coord_y * mat->img->height_multi) - ant->y)
			/ frames);
	return (true);
}

void			init_ants(t_img **img, t_ants *ant, t_vertex *vtx,
		t_adjmatrix *mat)
{
	t_vertex	*base;

	base = vtx;
	while (ant != NULL)
	{
		vtx = base;
		while (vtx != NULL && vtx->id != ant->path->tab[ant->room])
			vtx = vtx->next;
		if (vtx == NULL)
			break ;
		ant->x = (int)(vtx->coord_x * (*img)->width_multi);
		ant->y = (int)(vtx->coord_y * (*img)->height_multi);
		vtx = base;
		if (get_pas((*img)->ant_frames, ant, vtx, mat) == error)
			break ;
		place_ants(img, ant->x, ant->y);
		ant = ant->next;
	}
}

void			draw_ants(t_adjmatrix *mat, t_ants *ants,
		t_img **img, t_vertex *vtx)
{
	t_ants		*base;
	int			i;

	init_ants(img, ants, vtx, mat);
	i = 0;
	base = ants;
	while (i < (*img)->ant_frames)
	{
		initial_placing(mat, *img, vtx);
		ants = base;
		while (ants != NULL)
		{
			if (ants->path->tab[ants->room] != mat->end)
				place_ants(img, ants->x, ants->y);
			get_pas((*img)->ant_frames - i, ants, vtx, mat);
			ants->x += ants->pasx;
			ants->y += ants->pasy;
			ants = ants->next;
		}
		SDL_RenderPresent((*img)->renderer);
		SDL_Delay(10);
		++i;
	}
	SDL_Delay(80);
	poll_event(img);
}
