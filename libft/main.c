#include <stdio.h>
#include "libft.h"
#include <string.h>

int main()
{
	char	s1[5] = "hellm";
	char	s2[5] = "hello";

	printf("%d\n", strncmp(s1, s2, 5));
	printf("%d\n", ft_strncmp(s1, s2, 5));

	return 0;
}
