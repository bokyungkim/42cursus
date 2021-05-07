/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:33:16 by bokim             #+#    #+#             */
/*   Updated: 2021/05/07 18:02:33 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = (char	*)malloc(sizeof(char) * ft_strlen(s1));
	if (ptr == 0)
		return ((char *)0);
	i = 0;
	while (i < ft_strlen(s1))
	{
		j = 0;
		while (j < ft_strlen(set))
		{
			ft_strchr(s1, (int)(set[j])
		}
	}
}
