all:
	arch -x86_64 gcc -g -L./mlx -lmlx -framework OpenGL -framework AppKit ./srcs/main.c
	./a.out

clean:
	rm -rf *.out

re:
	make clean
	make all
