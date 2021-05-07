/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:53:43 by bokim             #+#    #+#             */
/*   Updated: 2021/05/06 15:21:12 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t j;

	if (!*to_find)
		return ((char *)str);
	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		while (to_find[j] && i < len)
		{
			if (str[i] == to_find[j])
			{
				i++;
				j++;
			}
			else
				break ;
		}
		if (!to_find[j])
			return ((char *)(str + i - j));
		i++;
	}
	return ((char *)0);
}
