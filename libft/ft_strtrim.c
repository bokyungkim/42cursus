/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:33:16 by bokim             #+#    #+#             */
/*   Updated: 2021/05/07 19:18:34 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		first;
	int		last;

	if (s1 == 0)
		return (0);
	else if (set == 0)
		return (ft_strdup(s1));
	first = 0;
	last = ft_strlen(s1);
}
