/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 21:16:02 by bokim             #+#    #+#             */
/*   Updated: 2021/05/04 21:16:05 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t src_size;

	i = 0;
	src_size = 0;
	if (!dst || !src)
		return (0);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
		src_size++;
	}
	dst[i] = '\0';
	while (src[i])
	{
		i++;
		src_size++;
	}
	return (src_size);
}
