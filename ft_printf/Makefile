# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bokim <bokim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 16:50:58 by bokim             #+#    #+#              #
#    Updated: 2021/07/07 00:20:22 by bokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft
LIBFT_LIB = libft.a

SRCS = ft_printf.c \
	   ft_putchar.c \
	   ft_parse.c \
	   ft_conversion.c \
	   ft_convert_char.c \
	   ft_convert_int.c \
	   ft_convert_str.c \
	#    main.c
INCLUDE = ft_printf.h
OBJS = ${SRCS:.c=.o}
RM = rm -rf

LIBC = ar rcs
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

all: ${NAME} #${CC}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCLUDE}

${NAME} : ${OBJS}
	make all -C ${LIBFT}/
	cp ${LIBFT}/${LIBFT_LIB} ${NAME}
	${LIBC} ${NAME} ${OBJS}

# ${CC}:
# 		${CC} ${CFLAGS} ${SRCS} ${INCLUDE} -L./libft -lft
# 		./a.out

clean:
		${RM} ${OBJS} a.out a.out.dSYM ft_printf.h.gch
		make clean -C ${LIBFT}

fclean: clean
		${RM} ${NAME}
		make fclean -C ${LIBFT}

re: fclean all

.PHONY: all clean fclean re
