# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keenouxe <keenouxe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/19 08:23:39 by keenouxe          #+#    #+#              #
#    Updated: 2019/04/20 19:31:48 by jucapik          ###   ########.fr        #
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
			sdl_image/SDL2_image-2.0.3/include/SDL2	\
			sdl_main/SDL2-2.0.8/include/SDL2

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
SDL_MAIN_DOWNLOAD = https://www.libsdl.org/release/SDL2-2.0.8.tar.gz
SDL_IMAGE_DOWNLOAD = https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.3.tar.gz

LIBSDL			=   SDL2
LIBSDLIMG		=   SDL2_image

LFLAG		=		-L sdl_main/SDL2-2.0.8/lib  -lSDL2					\
					-L ./sdl_image/SDL2_image-2.0.3/lib -lSDL2_image	\


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

all		:	lib $(NAME)

re		:	fclean default

#	Graphic Library rules

lib: sdl_main sdl_image

sdl_main:
	@if [ -d "./sdl_main/" ]; then \
		echo "SDL (main) ==> Nothing to be done"; \
		else \
		mkdir sdl_main && \
		echo "SDL (main) ==> Downloading SDL" && \
		cd ./sdl_main && \
		curl -s $(SDL_MAIN_DOWNLOAD) -O && \
		echo "SDL (main) ==> Compilation SDL main" && \
		tar xzf SDL2-2.0.8.tar.gz && \
		cd SDL2-2.0.8 && \
		./configure --prefix=$(shell pwd)/sdl_main/SDL2-2.0.8 > /dev/null && \
		$(MAKE) > /dev/null &&  \
		$(MAKE) install > /dev/null && \
		echo "SDL (main) ==> DONE"; \
		fi


sdl_image:
	@if [ -d "./sdl_image/" ]; then \
		echo "SDL (image) ==> Nothing to be done"; \
		else \
		mkdir sdl_image && \
		echo "SDL (image) ==> Downloading SDL image" && \
		cd ./sdl_image && \
		curl -s $(SDL_IMAGE_DOWNLOAD) -O && \
		echo "SDL (image) ==> Compilation SDL image" && \
		tar xzf SDL2_image-2.0.3.tar.gz && \
		cd SDL2_image-2.0.3 && \
		./configure --prefix=$(shell pwd)/sdl_image/SDL2_image-2.0.3 --with-sdl-prefix=$(shell pwd)/sdl_main/SDL2-2.0.8  > /dev/null && \
		$(MAKE)  > /dev/null  &&  \
		$(MAKE) install > /dev/null  && \
		echo "SDL (image) ==> DONE"; \
		fi

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
		$(LFLAG) -lSDL2 -lSDL2_image

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
