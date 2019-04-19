# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klebon <klebon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/20 19:59:37 by klebon            #+#    #+#              #
#    Updated: 2019/03/09 14:51:27 by klebon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

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
LIBDIR	=
SRCDIR	=	srcs
OBJDIR	=	objs
INCDIR	=	includes

#	Source files
SRC	=		basics/ft_putchar.c							\
			basics/ft_putstr.c							\
			basics/ft_putnbr.c							\
			basics/ft_putchar_fd.c						\
			basics/ft_putstr_fd.c						\
			basics/ft_putendl_fd.c						\
			basics/ft_putnbr_fd.c						\
			basics/ft_putendl.c							\
			basics/ft_memalloc.c						\
			basics/ft_memdel.c							\
			basics/ft_strnew.c							\
			basics/ft_strdel.c							\
			basics/ft_strclr.c							\
			basics/ft_striter.c							\
			basics/ft_striteri.c						\
			basics/ft_strlen.c							\
			basics/ft_strmap.c							\
			basics/ft_strmapi.c							\
			basics/ft_strcmp.c							\
			basics/ft_strequ.c							\
			basics/ft_strncmp.c							\
			basics/ft_strnequ.c							\
			basics/ft_strsub.c							\
			basics/ft_strjoin.c							\
			basics/ft_strtrim.c							\
			basics/ft_strsplit.c						\
			basics/ft_isalpha.c							\
			basics/ft_isdigit.c							\
			basics/ft_isalnum.c							\
			basics/ft_isascii.c							\
			basics/ft_isprint.c							\
			basics/ft_tolower.c							\
			basics/ft_toupper.c							\
			basics/ft_atoi.c							\
			basics/ft_memset.c							\
			basics/ft_bzero.c							\
			basics/ft_memcpy.c							\
			basics/ft_memccpy.c							\
			basics/ft_memmove.c							\
			basics/ft_memchr.c							\
			basics/ft_memcmp.c							\
			basics/ft_strdup.c							\
			basics/ft_strcpy.c							\
			basics/ft_strncpy.c							\
			basics/ft_strcat.c							\
			basics/ft_strncat.c							\
			basics/ft_strlcat.c							\
			basics/ft_strchr.c							\
			basics/ft_strrchr.c							\
			basics/ft_strstr.c							\
			basics/ft_strnstr.c							\
			basics/ft_itoa.c							\
			basics/ft_print_words_tables.c				\
			basics/ft_sort_integer_table.c				\
			basics/ft_islower.c							\
			basics/ft_str_is_lowercase.c				\
			basics/ft_isupper.c							\
			basics/ft_str_is_uppercase.c				\
			basics/ft_str_is_alpha.c					\
			basics/ft_str_is_numeric.c					\
			basics/ft_str_is_printable.c				\
			basics/ft_strcpy_s.c						\
			basics/ft_strncpy_s.c						\
			\
			list/ft_lstnew.c							\
			list/ft_lstdelone.c							\
			list/ft_lstdel.c							\
			list/ft_lstadd.c							\
			list/ft_lstiter.c							\
			list/ft_lstmap.c							\
			list/ft_lstappend.c							\
			list/ft_lstlen.c							\
			list/ft_lststrtotab.c						\
			\
			maths/ft_recursive_power.c					\
			maths/ft_min.c								\
			\
			base/ft_isinbase.c							\
			base/ft_atoi_base.c							\
			base/ft_itoa_base.c							\
			base/ft_convert_base.c						\
			\
			utils/ft_realloc.c							\
			utils/ft_strtabdel.c						\
			utils/ft_strtablen.c						\
			utils/ft_strnjoin.c							\
			utils/ft_strndup.c							\
			\
			gnl/get_next_line.c							\
			\
			ft_printf/ft_printf.c						\
			ft_printf/ft_printf_check_fields.c			\
			ft_printf/ft_printf_check_type.c			\
			ft_printf/ft_printf_tools.c					\
			ft_printf/ft_printf_tools_char.c			\
			ft_printf/ft_printf_tools_hexa.c			\
			ft_printf/ft_printf_tools_int.c				\
			ft_printf/ft_printf_tools_oct.c				\
			ft_printf/ft_printf_tools_str.c				\
			ft_printf/ft_printf_tools_unsigned_int.c	\
			ft_printf/ft_printf_tools_wchar_t.c			\
			ft_printf/ft_printf_tools_wstr.c			\
			ft_printf/ft_printf_tools_lenght.c			\
			ft_printf/ft_printf_tools_malloc_size.c		\
			ft_printf/ft_printf_tools_prec_size.c

OBJ		=	$(SRC:.c=.o)

LIB		=

#	Prefixes
OBJP		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCP 		=	$(foreach dir, $(INCDIR), -I$(dir))
OBJS_DIRS	=	$(sort $(dir $(OBJP)))
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

$(OBJDIR)/%.o	:	$(SRCDIR)/%.c
		$(CC) $(FLAGS) -c -o $@ $^ -I$(INCDIR)

$(OBJDIR)	:
		$(ECHO) "$(YEL)===> $(GRE)$(NAME) : $(YEL) Objects Compilation <===$(DEF)"
		@mkdir -p $(OBJDIR)
		@mkdir -p $(OBJS_DIRS)

$(NAME)	:	$(OBJDIR) $(OBJP)
		$(ECHO) "$(YEL)===> $(GRE)$(NAME) : $(YEL) Binary Compilation <===$(DEF)"
		ar rc $(NAME) $(OBJP)
		ranlib $(NAME)

#	Cleaner rules
clean	:
		$(ECHO) "$(RED)===> $(GRE)$(NAME) : $(RED) Delete Object Files <===$(DEF)"
		@rm -rf $(OBJDIR)

fclean	:	clean
		$(ECHO) "$(RED)===> $(GRE)$(NAME) : $(RED) Delete Binary File <===$(DEF)"
		@rm -f $(NAME)

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
