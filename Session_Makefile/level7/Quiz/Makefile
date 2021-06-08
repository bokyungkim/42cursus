NAME = libft.a
SRCS = first.c \
	second.c \
	third.c \
	main.c
OBJS = $(SRCS:.c=.o)
AR = ar
ARFLAGS = rcs
RM = rm

all : $(NAME)
	gcc -o main $(NAME)


$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	$(RM) -f *.o

fclean : clean
	$(RM) -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
