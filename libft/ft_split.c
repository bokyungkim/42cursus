/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:26:44 by bokim             #+#    #+#             */
/*   Updated: 2021/05/10 21:48:31 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_count(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

static int		get_word_size(char const *s, char c)
{
	int		i;

	i = 0;
	while (*s != c && *s != 0)
	{
		s++;
		i++;
	}
	return (i);
}

static void		free_res(char **res, int i)
{
	while (i + 1 > 0)
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
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			word_size = get_word_size(s, c);
			if (!(res[i] = (char *)malloc(sizeof(char) * (word_size + 1))))
			{
				free_res(res, i);
				return (1);
			}
			j = 0;
			while (*s && *s != c)
				res[i][j++] = *s++;
			res[i++][j] = '\0';
		}
	}
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (0);
	words = word_count(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * (words + 1))))
		return (0);
	if (fill(res, s, c))
		return (0);
	res[words] = NULL;
	return (res);
}
