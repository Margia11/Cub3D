# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 15:58:38 by amargiac          #+#    #+#              #
#    Updated: 2023/09/27 13:36:50 by andreamargi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINILIBX_PATH	=	./mlx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a
LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES_FILES	=	cube.c\
					controls1.c\
					controls2.c\
					controls3.c\
					init.c\
					get_next_line/get_next_line.c\
					get_next_line/get_next_line_utils.c\
					parser.c \

HEADER			=	./Cub3d.h

OBJECTS			= 	$(SOURCES_FILES:.c=.o)

NAME			=	cub3d

CC				=	gcc

RM				=	rm -f

MLX				=	./libmlx.dylib

CFLAGS			=	-Wall -Wextra -Werror

MLX_FLAGS		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) ${CFLAGS} -Imlx -c $< -o $@

all:			$(NAME)

$(NAME):	$(OBJECTS) $(LIBFT)
				$(CC) $(OBJECTS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(MINILIBX):
				make -C $(MINILIBX_PATH)

$(LIBFT):
				make -C $(LIBFT_PATH)

clean:
				${RM} ${OBJECTS}
				make clean -C ${LIBFT_PATH}

fclean:			clean
					rm -f $(NAME)
					rm -f $(LIBFT)

re:				fclean all

.PHONY:			all clean re
