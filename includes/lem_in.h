/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:29:43 by klebon            #+#    #+#             */
/*   Updated: 2019/04/20 19:26:46 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "SDL.h"
# include "SDL_image.h"

# define PATH_BUFF 1000

# define ANT_TEX_PATH "textures/ant.png"
# define RUIN_TEX_PATH "textures/ruin.png"
# define BACKROUND_TEX_PATH "textures/backround.png"
# define MANSION_TEX_PATH "textures/mansion.png"
# define HOUSE_TEX_PATH "textures/house.png"

typedef enum	e_bool
{
	true,
	false,
	error,
	neg
}				t_bool;

/*
** linked list for paths
*/
typedef struct	s_path_tab
{
	int					size;
	int					nb_ants;
	int					tab[PATH_BUFF];
	struct s_path_tab	*next;
}				t_path_tab;

/*
** Store input file (we need to output the file before the answer)
*/
typedef struct	s_input
{
	char			*line;
	struct s_input	*next;
}				t_input;

/*
** Adjacency list store all edges from a vertice
*/

typedef struct	s_adjacency
{
	int					id;
	int					father_id;
	int					weight;
	int					next_in_order;
	struct s_adjacency	*next;
}				t_adjacency;

/*
** Vertex list store informations aff al Vertex...
*/
typedef struct	s_vertex
{
	int				id;
	char			*name;
	int				coord_x;
	int				coord_y;
	struct s_vertex	*next;
}				t_vertex;

/*
** Information for image
*/
typedef struct	s_img
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_bool		quit;
	SDL_Event		event;
	int				height;
	int				width;
	SDL_Texture		*ant_tex;
	SDL_Texture		*house_tex;
	SDL_Texture		*mansion_tex;
	SDL_Texture		*backround_tex;
	SDL_Texture		*ruin_tex;
	int				tex_size;
	double			width_multi;
	double			height_multi;
	int				ant_frames;
	t_bool			bl;
}				t_img;

typedef struct	s_pixel_position
{
	int				x;
	int				y;
}				t_pixpos;

typedef struct	s_pixel_position_doubles
{
	double			x;
	double			y;
}				t_pixposd;

/*
** Store a tab with all edges of the maps with start and end
*/
typedef struct	s_adjmatrix
{
	int			start;
	int			end;
	int			ants;
	t_adjacency	**tab;
	t_bool		*visited;
	t_bool		*old_visited;
	t_input		*input;
	t_img		*img;
	t_bool		opt_nblines;
	t_bool		opt_paths;
}				t_adjmatrix;

typedef struct	s_ants
{
	int				number;
	int				room;
	int				x;
	int				y;
	int				pasx;
	int				pasy;
	t_path_tab		*path;
	struct s_ants	*next;
}				t_ants;

/*
** Memory
*/
t_bool			add_vertex(t_vertex **vtx, char *name, int x, int y);
void			delete_vertex(t_vertex **vtx);
t_bool			add_adjacency(t_adjacency **adj, int id);
t_bool			add_input_line(t_input **input, char **str);
void			delete_path_tab(t_path_tab ***p);
t_bool			init_adjmatrix(t_adjmatrix **mat);
void			clean_memory(t_adjmatrix **mat, t_vertex **vtx);
void			del_ants(t_ants **ants);
void			del_all_ants(t_ants **ants);

/*
** Getter
*/
t_vertex		*get_last_vertex(t_vertex *vtx);
t_vertex		*get_vertex(t_vertex *vtx, char *name);
t_path_tab		**get_path_tab(t_adjmatrix *mat, int size);
/*
** Parsing
*/
t_bool			parser(t_vertex	**vtx, t_adjmatrix **mat);
t_bool			parse_mat(t_vertex *vtx, t_adjmatrix **mat, char **line);

/*
** Path finding
*/
t_path_tab		**solver(t_adjmatrix *mat);
t_bool			bfs(t_adjmatrix *mat, int start, int end);
t_bool			update_father_id(t_adjmatrix *mat,
		t_adjacency *con, int base);
t_bool			update_adjmatrix_path(t_adjmatrix *mat);
t_path_tab		**path_selection(t_path_tab ***path_1,
		t_path_tab ***path_2, int ants);
void			sort_paths(t_path_tab **tab);
int				path_size(t_path_tab *paths);
void			clean_next_in_order(t_adjmatrix *mat, t_adjacency *con);

void			select_path(t_path_tab ***paths, int ants, t_path_tab ***s);

/*
** Output
*/
t_bool			output_ants(t_path_tab **paths,
		t_vertex *vtx, t_adjmatrix *mat);
int				get_room(t_path_tab *paths, int room);
void			get_bonus(int ac, char **av, t_adjmatrix *mat, t_vertex *vtx);
void			print_opts(t_adjmatrix *mat, t_path_tab **paths, int nlines,
							char **out);
t_bool			output_all_ants(t_path_tab **paths, t_vertex *vtx,
							t_adjmatrix *mat);

/*
** Visualizer
*/

int				key_press(SDL_Event *event, t_img **img);
int				import_textures(t_img *img);
t_bool			initial_placing(t_adjmatrix *mat, t_img *img, t_vertex *vertex);
t_bool			create_graph_setting(t_adjmatrix *mat,
		t_img **img, t_vertex *vertex);
void			draw_line(t_img *img, t_pixpos p0, t_pixpos p1);
void			end_wait(t_img **img);
void			draw_ants(t_adjmatrix *mat, t_ants *ants,
		t_img **img, t_vertex *vertex);
void			init_ants(t_img **img, t_ants *ant,
		t_vertex *vtx, t_adjmatrix *mat);
void			poll_event(t_img **img);
void			close_window(t_img **img);

/*
** Helper
*/

void			insert_ants_helper(t_ants *new, t_path_tab **path,
		int i, int *number);
void			init_adjacency_tab_helper(t_adjmatrix **mat, int i);

#endif
