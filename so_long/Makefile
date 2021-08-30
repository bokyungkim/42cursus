# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 16:50:58 by bokim             #+#    #+#              #
#    Updated: 2021/08/30 17:26:52 by bokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LFT = ./libft/libft.a
MLX = mlx/Makefile.gen
LIB = -L ./libft -lft -L ./mlx -lmlx

INC_PATH = ./includes/
SRC_PATH = ./srcs/
INC = 	${INC_PATH}so_long.h
SRCS = 	${SRC_PATH}main.c \
		${SRC_PATH}init_game.c
OBJS = ${patsubst src%, objs%, ${SRCS:.c=.o}}

CC = gcc
RM = rm -rf

all: ${MLX} ${LFT} objs ${NAME}
	./so_long

${NAME}: ${OBJS}
	${CC} -o $@ $^ ${LIB}

${MLX}:
	make -s -C mlx

${LFT}:
	make -s -C libft

objs:
	mkdir -p objs

objs/%.o: srcs/%.c
	${CC} ${INC} -o $@ -c $<

clean:
	make -s $@ -C libft
	${RM} ${OBJS} objs

fclean: clean
	make -s $@ -C libft
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re