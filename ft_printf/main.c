#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("\n----test1----\n");
	ft_printf("%-3.*u", 1, 4294967284);
	printf("\n");
	printf("%-3.*u", 1, 4294967284);
	return (0);
}
