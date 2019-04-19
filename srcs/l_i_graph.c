/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_i_graph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <jucapik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 12:30:31 by jucapik           #+#    #+#             */
/*   Updated: 2019/03/09 10:25:06 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				key_press(SDL_Event *event, t_img **img)
{
	if (event->key.keysym.sym == SDLK_ESCAPE)
	{
		(*img)->quit = SDL_TRUE;
		close_window(img);
	}
	if (event->key.keysym.sym == SDLK_n)
		(*img)->bl = true;
	return (1);
}

static t_img	*init_graph(void)
{
	t_img		*img;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (NULL);
	img = (t_img *)malloc(sizeof(t_img));
	img->height = 1000;
	img->width = 1200;
	img->win = NULL;
	img->win = SDL_CreateWindow("Lem-in", 0, 0,
			img->width, img->height, SDL_WINDOW_SHOWN);
	img->renderer = NULL;
	img->renderer = SDL_CreateRenderer(img->win, -1, SDL_RENDERER_ACCELERATED);
	img->quit = SDL_FALSE;
	img->tex_size = 100;
	img->ant_frames = 50;
	img->ant_tex = NULL;
	img->backround_tex = NULL;
	img->ruin_tex = NULL;
	img->house_tex = NULL;
	img->mansion_tex = NULL;
	return (img);
}

void			poll_event(t_img **img)
{
	(*img)->bl = false;
	while (*img != NULL && !(*img)->quit && (*img)->bl == false)
	{
		if (SDL_PollEvent(&((*img)->event)) == 1)
		{
			if ((*img)->event.type == SDL_KEYDOWN)
				key_press(&(*img)->event, img);
			else if ((*img)->event.type == SDL_QUIT)
			{
				(*img)->quit = SDL_TRUE;
				close_window(img);
				*img = NULL;
			}
		}
	}
}

void			end_wait(t_img **img)
{
	while (*img != NULL && !(*img)->quit)
	{
		if (SDL_PollEvent(&((*img)->event)) == 1)
		{
			if ((*img)->event.type == SDL_KEYDOWN)
				key_press(&((*img)->event), img);
			else if ((*img)->event.type == SDL_QUIT)
			{
				(*img)->quit = SDL_TRUE;
				close_window(img);
				*img = NULL;
			}
		}
	}
}

t_bool			create_graph_setting(t_adjmatrix *mat,
		t_img **img, t_vertex *vertex)
{
	if ((*img = init_graph()) == NULL)
		return (false);
	if (import_textures(*img) == -1)
		return (error);
	initial_placing(mat, *img, vertex);
	SDL_RenderPresent((*img)->renderer);
	poll_event(img);
	return (true);
}
