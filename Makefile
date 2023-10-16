# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 15:58:38 by amargiac          #+#    #+#              #
#    Updated: 2023/10/16 12:19:53 by andreamargi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINILIBX_PATH	=	./mlx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a
LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MAKEFLAGS += --silent

SOURCES_FILES	=	cube.c\
					controls1.c\
					controls2.c\
					controls3.c\
					init1.c\
					init2.c\
					init3.c\
					init4.c\
					get_next_line/get_next_line.c\
					get_next_line/get_next_line_utils.c\
					parser.c \
					player1.c \
					player2.c \
					game1.c \
					game2.c \
					raycasting1.c \
					raycasting2.c \
					minimap1.c \
					minimap2.c \
					animation.c \
					fire.c \

HEADER			=	./Cub3d.h

OBJECTS			= 	$(SOURCES_FILES:.c=.o)

NAME			=	cub3d

CC				=	gcc

RM				=	rm -f

MLX				=	./libmlx.dylib

CFLAGS			=	-Wall -Wextra -Werror -g

MLX_FLAGS		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) ${CFLAGS} -Imlx -c $< -o $@

all:			$(NAME)

$(NAME):	$(OBJECTS) $(LIBFT)
				$(CC) $(OBJECTS) -g $(LIBFT) $(MLX_FLAGS) $(SILENT_FLAG) -o $(NAME)
		@echo "\033[32mCompiled OK!\033[0m"

$(MINILIBX):
				make -C $(MINILIBX_PATH)

$(LIBFT):
				make -C $(LIBFT_PATH)

clean:
				${RM} ${OBJECTS}
				make clean -C ${LIBFT_PATH}
		@echo "\033[33mclean OK!\033[0m"

fclean:			clean
					rm -f $(NAME)
					rm -f $(LIBFT)
		@echo "\033[33mfclean OK!\033[0m"

re:				fclean all

.PHONY:			all clean re
