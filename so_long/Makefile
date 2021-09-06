# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 16:50:58 by bokim             #+#    #+#              #
#    Updated: 2021/09/06 18:21:49 by bokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LFT = ./libft/libft.a
MLX = mlx/Makefile.gen
LIB = -L ./libft -lft -L ./mlx -lmlx

INC_PATH = ./includes/
SRC_PATH = ./srcs/
INC = 	${INC_PATH}so_long.h
SRC = 	main.c \
		init_game.c \
		map_read.c
SRCS = ${addprefix ${SRC_PATH}, ${SRC}}
OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -rf

all: ${NAME}
	./so_long ./maps/map.ber

${NAME}: ${OBJS}
	@make -s -C libft
	@make -s -C mlx
	@${CC} -g -o $@ $^ ${LIB} -framework OpenGL -framework Appkit

clean:
	@${RM} ${OBJS}
	@echo deleted all object files

fclean: clean
	@make -s $@ -C libft
	@make -s clean -C mlx
	@${RM} ${NAME}
	@echo deleted libft and mlx

re: clean all

.SILENT: ${OBJS}

.PHONY: all clean fclean re