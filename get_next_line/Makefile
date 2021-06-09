# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 16:50:58 by bokim             #+#    #+#              #
#    Updated: 2021/06/09 17:08:33 by bokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror -D BUFFER_SIZE=32

SRCS = get_next_line.c \
	   get_next_line_utils.c \
	   main.c

INCLUDE = get_next_line.h

OBJS = ${SRCS:.c=.o}

RM = rm -rf

all: ${CC}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${CC}:
		${CC} ${CFLAGS} ${SRCS} ${INCLUDE}
		./a.out

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} a.out *.h.gch a.out.dSYM

re: fclean all

.PHONY: all clean fclean re
