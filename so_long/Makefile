# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 16:50:58 by bokim             #+#    #+#              #
#    Updated: 2021/08/25 23:17:05 by bokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LFT = ./libft/libft.a
MLX = mlx/Makefile.gen
LIB = -L ./libft -lft -L ./mlx -lmlx

INC = ./srcs/so_long.h
SRCS = ./srcs/main.c
OBJS = ${patsubst src%, objs%, ${SRCS:.c=.o}}

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: ${MLX} ${LFT} objs ${NAME}
	./so_long

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -fsanitize=address -o $@ $^ ${LIB}

${MLX}:
	make -s -C mlx

${LFT}:
	make -s -C libft

objs:
	mkdir -p objs

objs/%.o: srcs/%.c
	${CC} ${CFLAGS} ${INC} -o $@ -c $<

clean:
	make -s $@ -C libft
	${RM} ${OBJS} objs

fclean: clean
	make -s $@ -C libft
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re