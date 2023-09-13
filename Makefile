# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 15:58:38 by amargiac          #+#    #+#              #
#    Updated: 2023/09/13 16:09:39 by andreamargi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cube3D

LIBFT_PATH = libft

GNL = Get_next_line
LIBFT = $(LIBFT_PATH)/libft.a

MAKEFLAGS += --silent

SRC = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
		controls1.c controls2.c parser.c utils.c cube.c \

OBJ = ${SRC:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -Iheaders
LIBRARY = -Lmlx_linux -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MINILIBX = ./mlx_linux

%.o: %.c
		${CC} ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

${NAME}: ${OBJ}
		make -C ${LIBFT_PATH}
		make -C ${MINILIBX}
		${CC} ${OBJ} ${LIBFT} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}

all:
		make -C ${LIBFT_PATH}
		make -C ${MINILIBX}
		${CC} ${CFLAGS} ${SRC} ${LIBFT} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}

clean:
		${RM} ${OBJ}

fclean: clean
		make clean -C ${MINILIBX}
		${RM} ${NAME}

re: fclean all
