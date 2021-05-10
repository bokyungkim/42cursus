/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:33:16 by bokim             #+#    #+#             */
/*   Updated: 2021/05/10 16:25:40 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_first(char const *s, char const *set)
{
	size_t	i;

	i = 0;
	while (ft_strchr(set, s[i]) && s[i])
		i++;
	return (i);
}

static size_t	find_last(char const *s, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (ft_strchr(set, s[len - i - 1]) && s[len - i - 1])
		i++;
	return (len - i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*ptr;
	size_t		first;
	size_t		last;

	if (!s1)
		return (0);
	else if (!set || ft_strncmp(s1, "", ft_strlen(s1)) == 0)
		return (ft_strdup(s1));
	first = find_first(s1, set);
	if (first == ft_strlen(s1))
		return (ft_strdup(""));
	last = find_last(s1, set);
	if (!(ptr = (char *)malloc(sizeof(char) * (last - first + 1))))
		return (0);
	ft_strlcpy(ptr, s1 + first, last - first + 1);
	return (ptr);
}
