/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 23:20:24 by bokim             #+#    #+#             */
/*   Updated: 2021/05/05 23:20:25 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	ptr = malloc(sizeof(char) * (i + 1));
	while (*s1)
	{
		ptr[j] = *s1;
		j++;
		s1++;
	}
	ptr[j] = '\0';
	return (ptr);
}
