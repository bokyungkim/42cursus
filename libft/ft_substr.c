/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:33:02 by bokim             #+#    #+#             */
/*   Updated: 2021/05/07 14:29:55 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *ptr;

	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == 0)
		return ((char *)0);
	if (start > ft_strlen(s))
		ft_strlcpy(ptr, "", 1);
	else
		ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}
