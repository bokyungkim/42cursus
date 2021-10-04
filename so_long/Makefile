# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 16:50:58 by bokim             #+#    #+#              #
#    Updated: 2021/10/05 00:02:00 by bokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LFT = ./libft/libft.a

LIB = -L ./libft -lft -L ./mlx -lmlx

FRMWRK = -framework OpenGL -framework Appkit

SRC_M_PATH = ./srcs/
SRC_B_PATH = ./bonus/
INC_M_PATH = ./includes/
INC_B_PATH = $(SRC_B_PATH)

SRC_M = 	main.c\
		init_game.c\
		map_read.c\
		free.c\
		map_draw.c\
		check.c\
		check_map.c\
		move.c
SRC_B = main_bonus.c\
		init_game_bonus.c\
		map_read_bonus.c\
		free_bonus.c\
		map_draw_bonus.c\
		check_bonus.c\
		check_map_bonus.c\
		move_bonus.c
		
SRCS_M = $(addprefix $(SRC_M_PATH), $(SRC_M))
SRCS_B = $(addprefix $(SRC_B_PATH), $(SRC_B))

OBJS_M = $(SRCS_M:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

ifdef HAS_BONUS
		OBJS = $(OBJS_B)
		INC_PATH = $(INC_B_PATH)
else
		OBJS = $(OBJS_M)
		INC_PATH = $(INC_M_PATH)
endif

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_PATH)

bonus:
	@make HAS_BONUS=1 all

$(NAME): $(OBJS)
	@make -s -C libft
	@make -s -C mlx
	@$(CC) $(CFLAGS) -o $@ $^ $(LIB) $(FRMWRK)

clean:
	@make -s $@ -C libft
	@make -s $@ -C mlx
	@$(RM) $(OBJS_M) $(OBJS_B)
	@echo deleted all object files

fclean: clean
	@$(RM) $(NAME)
	@echo deleted libft and mlx

re: fclean all

.SILENT: $(OBJS)

.PHONY: all clean fclean re bonus