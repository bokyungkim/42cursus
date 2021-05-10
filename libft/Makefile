# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 16:50:58 by bokim             #+#    #+#              #
#    Updated: 2021/05/10 23:48:54 by bokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c\
	   ft_bzero.c\
	   ft_calloc.c\
	   ft_isalnum.c\
	   ft_isalpha.c\
	   ft_isascii.c\
	   ft_isdigit.c\
	   ft_isprint.c\
	   ft_memccpy.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_memcpy.c\
	   ft_memmove.c\
	   ft_memset.c\
	   ft_strchr.c\
	   ft_strdup.c\
	   ft_strlcat.c\
	   ft_strlcpy.c\
	   ft_strlen.c\
	   ft_strncmp.c\
	   ft_strnstr.c\
	   ft_tolower.c\
	   ft_toupper.c\
	   ft_substr.c\
	   ft_strjoin.c\
	   ft_strtrim.c\
	   ft_split.c\
	   ft_itoa.c\
	   ft_strmapi.c\
	   ft_putchar_fd.c\
	   ft_putstr_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c\

INCLUDE = libft.h

OBJS = ${SRCS:.c=.o}

RM = rm -f

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
			ar rcs $@ $^

wgcc: ${SRCS}
	${CC} ${CFLAGS} -g ${SRCS} main.c ${INCLUDE}
	./a.out

clean:
		${RM} ${OBJS}

gclean:
		${RM} -rf a.out a.out.dSYM libft.h.gch

fclean: clean gclean
		${RM} ${NAME}

re: fclean all

.PHONY: all wgcc clean gclean fclean re
