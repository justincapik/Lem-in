/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_i_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <jucapik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 09:53:43 by jucapik           #+#    #+#             */
/*   Updated: 2019/03/09 09:06:08 by klebon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					get_x_max(t_vertex *vertex)
{
	int		max;

	max = -1;
	while (vertex != NULL)
	{
		if (max < vertex->coord_x)
			max = vertex->coord_x;
		vertex = vertex->next;
	}
	return (max);
}

static SDL_Texture	*create_texture(t_img *img, char *path)
{
	SDL_Surface		*surface;
	SDL_Texture		*texture;

	if ((surface = IMG_Load(path)) == NULL)
		return (NULL);
	if ((texture = SDL_CreateTextureFromSurface(img->renderer, surface))
			== NULL)
		return (NULL);
	SDL_FreeSurface(surface);
	return (texture);
}

int					import_textures(t_img *img)
{
	if ((img->house_tex = create_texture(img, HOUSE_TEX_PATH)) == NULL)
		return (-1);
	if ((img->ant_tex = create_texture(img, ANT_TEX_PATH)) == NULL)
		return (-1);
	if ((img->mansion_tex = create_texture(img, MANSION_TEX_PATH)) == NULL)
		return (-1);
	if ((img->backround_tex = create_texture(img, BACKROUND_TEX_PATH)) == NULL)
		return (-1);
	if ((img->ruin_tex = create_texture(img, RUIN_TEX_PATH)) == NULL)
		return (-1);
	return (1);
}
