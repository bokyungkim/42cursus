#include <stdio.h>
#include "libft.h"
#include <string.h>
int main()
{
	char *i1 = ft_itoa(-623);
	char *i2 = ft_itoa(156);
	char *i3 = ft_itoa(-0);

		printf("%s\n", i1);
	if (strcmp(i2, "156"))
	{
		write(1,"KO2\n",4);
	}
	if (strcmp("0", i3))
	{
		write(1,"Ko3\n",4);
	}
	write(1,"OK\n",3);
}
