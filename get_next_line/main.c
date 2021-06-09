#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	char* line;
	int	check;
	int	fd;

	fd = open("test.txt", O_RDONLY);
	while ((check = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s\n", line);
	free(line);
	line = NULL;
	return (0);
}