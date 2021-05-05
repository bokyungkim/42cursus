/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:55:19 by bokim             #+#    #+#             */
/*   Updated: 2021/05/05 22:55:44 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = malloc(size * count);
	i = 0;
	while (ptr[i])
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
