/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:41:58 by jucapik           #+#    #+#             */
/*   Updated: 2019/03/08 14:53:39 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_abs(int n)
{
	return ((n < 0) ? -n : n);
}

static void	x_mov(t_img *img, t_pixpos p0, t_pixpos p1)
{
	float		slope;
	float		pitch;
	t_pixposd	d;
	t_pixposd	s;

	d.x = p1.x - p0.x;
	s.x = (d.x < 0) ? -1 : 1;
	d.y = p1.y - p0.y;
	s.y = (d.y < 0) ? -1 : 1;
	slope = d.y / d.x;
	pitch = p0.y - slope * p0.x;
	while (p0.x != p1.x)
	{
		SDL_RenderDrawPoint(img->renderer,
				p0.x, (int)(slope * p0.x + pitch));
		p0.x += s.x;
	}
}

static void	y_mov(t_img *img, t_pixpos p0, t_pixpos p1)
{
	float		slope;
	float		pitch;
	t_pixposd	d;
	t_pixposd	s;

	d.x = p1.x - p0.x;
	s.x = (d.x < 0) ? -1 : 1;
	d.y = p1.y - p0.y;
	s.y = (d.y < 0) ? -1 : 1;
	slope = d.x / d.y;
	pitch = p0.x - slope * p0.y;
	while (p0.y != p1.y)
	{
		SDL_RenderDrawPoint(img->renderer,
				(int)(slope * p0.y + pitch), p0.y);
		p0.y += s.y;
	}
}

void		draw_line(t_img *img, t_pixpos p0, t_pixpos p1)
{
	t_pixposd	d;
	t_pixpos	s;

	d.x = p1.x - p0.x;
	s.x = (d.x < 0) ? -1 : 1;
	d.y = p1.y - p0.y;
	s.y = (d.y < 0) ? -1 : 1;
	if (ft_abs(d.y) < ft_abs(d.x))
		x_mov(img, p0, p1);
	else
		y_mov(img, p0, p1);
}
