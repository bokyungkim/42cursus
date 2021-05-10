#include <stdio.h>
#include "libft.h"

int main ()
{
	printf("%d\n", ft_strncmp("test\200", "test\0", 6));
	return 0; //1 나와
}
