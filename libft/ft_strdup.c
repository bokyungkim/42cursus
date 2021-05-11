/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 23:20:24 by bokim             #+#    #+#             */
/*   Updated: 2021/05/12 01:41:24 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	if (!(ptr = malloc(sizeof(char) * (i + 1))))
		return (0);
	while (*s1)
	{
		ptr[j] = *s1;
		j++;
		s1++;
	}
	ptr[j] = '\0';
	return (ptr);
}
