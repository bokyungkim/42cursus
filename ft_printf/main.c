#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("\n----test1----\n");
	ft_printf("%03d", -1);
	printf("\n");
	printf("%03d", -1);
	return (0);
}