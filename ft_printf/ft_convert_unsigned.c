/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:40:07 by bokim             #+#    #+#             */
/*   Updated: 2021/07/07 20:13:15 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_lnumsize(unsigned int n, int base)
{
	int		size;

	size = 0;
	if (n == 0)
		size = 1;
	else
	{
		if (n < 0)
			n *= -1;
		while (n > 0)
		{
			n /= base;
			size++;
		}
	}
	return (size);
}

static void	ft_putlnbr_fd(unsigned int n, int fd)
{
	char	ch;

	if (fd < 0)
		return ;
	if (n >= 10)
		ft_putlnbr_fd(n / 10, fd);
	ch = (n % 10) + '0';
	write(fd, &ch, 1);
}

static void	ft_putl_right(t_opt *option, unsigned int n, int num_size)
{
	ft_putspace(option->width - option->precision);
	ft_putzero(option->precision - num_size);
	ft_putlnbr_fd(n, 1);
}

static void	ft_putl_left(t_opt *option, unsigned int n, int num_size)
{
	ft_putzero(option->precision - num_size);
	ft_putlnbr_fd(n, 1);
	ft_putspace(option->width - option->precision);
}

int	ft_convert_unsigned(unsigned int n, t_opt *option)
{
	int		num_size;

	if (n == 0 && option->precision == 0)
	{
		ft_putspace(option->width);
		return (option->width);
	}
	num_size = ft_get_lnumsize(n, 10);
	if (option->zero == 1 && option->precision <= -1)
		option->precision = option->width;
	if (option->precision <= -1 || option->precision < num_size)
		option->precision = num_size;
	if (option->left == 0)
		ft_putl_right(option, n, num_size);
	else
		ft_putl_left(option, n, num_size);
	if (option->width > option->precision)
		return (option->width);
	else
		return (option->precision);
}