/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:48:04 by bokim             #+#    #+#             */
/*   Updated: 2021/05/10 23:09:56 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		num_len(int n)
{
	int		len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	char	sign;
	int		len;

	if (n < 0)
		sign = '-';
	len = num_len(n);
	if (!(res = malloc(sizeof(char) * len + 1)))
		return (0);
	res[len] = '\0';
	len--;
	if (n == 0)
		res[len] = '0';
	while (n != 0)
	{
		if (n > 0)
			res[len] = '0' + (n % 10);
		else
			res[len] = '0' + (n % 10 * (-1));
		n /= 10;
		len--;
	}
	if (sign == '-')
		res[0] = sign;
	return (res);
}
