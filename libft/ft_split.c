/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:26:44 by bokim             #+#    #+#             */
/*   Updated: 2021/05/13 18:17:52 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_count(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (count);
}

static int		get_word_size(char const *s, char c)
{
	int		i;

	i = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

static void		free_res(char **res, int i)
{
	while (i >= 0)
	{
		free(res[i]);
		i--;
	}
	free(res);
}

static int		fill(char **res, char const *s, char c)
{
	int		i;
	int		j;
	int		word_size;

	i = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			word_size = get_word_size(s, c);
			res[i] = (char *)ft_calloc(word_size + 1, sizeof(char));
			if (!res[i])
			{
				free_res(res, i);
				return (1);
			}
			j = 0;
			while (*s != '\0' && *s != c)
				res[i][j++] = *s++;
			i++;
		}
	}
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	if (ft_strncmp(s, "", 1) == 0)
	{
		res = (char **)ft_calloc(2, sizeof(char *));
		if (!res)
			return (NULL);
		res[0] = "";
		return (res);
	}
	res = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!res)
		return (NULL);
	if (fill(res, s, c))
		return (NULL);
	return (res);
}
