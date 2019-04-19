# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keenouxe <keenouxe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/19 08:23:39 by keenouxe          #+#    #+#              #
#    Updated: 2019/03/11 19:31:52 by jucapik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	lem-in
#	Make options
MAKEFLAGS	+=	--no-print-directory

#	Output
UNAME	:=	$(shell uname)
ifeq ($(UNAME), Darwin)
ECHO	=	@echo
endif

ifeq ($(UNAME), Linux)
ECHO	=	@echo -e
endif

#	Compilator
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror

#	Folders
LIBDIR	=	lib$(LIB)
SRCDIR	=	srcs
OBJDIR	=	objs
INCDIR	=	includes							\
			libft/includes						\
			libui/SDL/SDL2						\
			libui/SDL_image/include/SDL2

#	Source files
SRC =	l_i_graph.c								\
		l_i_textures.c							\
		l_i_texture_placing.c					\
		l_i_lines.c								\
		l_i_draw_ants.c							\
		l_i_window_cleaner.c					\
		l_i_getter.c							\
		l_i_main.c								\
		l_i_memory_allocation.c					\
		l_i_memory_cleaner.c					\
		l_i_parse_mat.c							\
		l_i_parser.c							\
		l_i_solver.c							\
		l_i_path_tab.c							\
		l_i_bfs_path.c							\
		l_i_bfs.c								\
		l_i_output_ants.c						\
		l_i_sort_path.c							\
		l_i_ants_management.c					\
		l_i_path_tab_tools.c					\
		l_i_bonus.c								\
		l_i_helper.c

#	Graphic folders
LIBSDL			=   SDL2
LIBSDLPATH		=   libui/SDL
LIBSDLFLAGS 	= 	-L $(LIBSDLPATH) -l $(LIBSDL)	\
					$(sdl2-config --cflags --libs)
LIBSDLIMG		=   SDL2_image
LIBSDLIMGPATH	=   libui/SDL_image/lib
LIBSDLIMGFLAGS	= 	-L $(LIBSDLIMGPATH) -l $(LIBSDLIMG)	\
					$(sdl2-config --cflags --libs) \

OBJ		=	$(SRC:.c=.o)

LIB		=	ft

#	Prefixes
OBJP	=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCP 	=	$(foreach dir, $(INCDIR), -I$(dir))
LLIBP =		$(addprefix -l, $(LIB))
LIBNAME =	$(addprefix lib, $(LIB))
LIBP =		$(addprefix -L, $(LIBNAME)/)

#	Compilator
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror

#	Default Rule
DRULE	=	all

#	Main rules
default	:
		$(ECHO) "$(PUR)===> $(GRE)$(NAME) : $(PUR) START RULE : $(DRULE) <===$(DEF)"
		@make $(DRULE)
		$(ECHO) "$(PUR)===> $(GRE)$(NAME) : $(PUR) END RULE : $(DRULE) <===$(DEF)"

all		:	$(NAME)

re		:	fclean default

#	Compilation rules
libft/libft.a	:
		$(ECHO) "$(YEL)===> $(GRE)lib$(LIB)$(YEL) Compilation <===$(DEF)"
		@make all -C lib$(LIB)

$(OBJDIR)/%.o	:  $(SRCDIR)/%.c includes/lem_in.h
		@mkdir -p $(OBJDIR)
		$(CC) $(FLAGS) $(INCP) -c -o $@ $<

$(NAME)	:	libft/libft.a $(OBJP)
		$(ECHO) "$(YEL)===> $(GRE)$(NAME) : $(YEL) Binary Compilation <===$(DEF)"
		$(CC) $(FLAGS) -o $@ $(OBJP) $(INCP) $(LIBP) $(LLIBP) \
			$(LIBSDLFLAGS) $(LIBSDLIMGFLAGS)

#	Cleaner rules
clean	:
		$(ECHO) "$(RED)===> $(GRE)$(NAME) : $(RED) Delete Object Files <===$(DEF)"
		@rm -rf $(OBJDIR)

fclean	:	clean
		$(ECHO) "$(RED)===> $(GRE)$(NAME) : $(RED) Delete Binary File <===$(DEF)"
		@rm -f $(NAME)
		$(ECHO) "$(RED)===> Delete $(GRE)lib$(LIB)$(RED) <===$(DEF)"
		@make fclean -C lib$(LIB)

#	Phony
.PHONY	=	default all re clean fclean $(OBJDIR) $(NAME)
#	Color
DEF		=	\033[0m
BLA		=	\033[30m
BLI		=	\033[5m
BLU		=	\033[34m
CYA		=	\033[36m
GRA		=	\033[1m
GRE		=	\033[32m
PUR		=	\033[35m
RED		=	\033[31m
SOU		=	\033[4m
WHI		=	\033[37m
YEL		=	\033[33m
