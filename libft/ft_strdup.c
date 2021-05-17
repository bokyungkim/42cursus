/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 23:20:24 by bokim             #+#    #+#             */
/*   Updated: 2021/05/17 17:22:26 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*ptr;
	unsigned int	len;
	unsigned int	j;

	len = 0;
	j = 0;
	while (s1[len] != '\0')
		len++;
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (0);
	while (*s1)
	{
		ptr[j] = *s1;
		j++;
		s1++;
	}
	return (ptr);
}
