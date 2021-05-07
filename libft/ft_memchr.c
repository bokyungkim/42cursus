/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:19:15 by bokim             #+#    #+#             */
/*   Updated: 2021/05/06 15:19:03 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	if (!s)
		return ((void *)0);
	while (i < n)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		i++;
		ptr++;
	}
	return ((void *)0);
}
