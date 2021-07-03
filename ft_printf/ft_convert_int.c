/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:46:55 by bokim             #+#    #+#             */
/*   Updated: 2021/07/03 17:20:35 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// precision < nbr_size 라면 빈 공간에 0 출력
// 		ex) printf("%5.3d", 1) >> [  001]
// num과 precision이 0인 경우, width만큼 공백을 출력
// num이 음수일 때, '-'는 precision의 크기에 포함되지 않음
// 음수일 때, '-'는 nbr_size에 포함되지 않음
// 		ex) -14 => nbr_size = 2
int		ft_convert_int(int n, t_opt *option)
{
	int		num_size;
	int		minus;

	num_size = ft_get_numsize(n, 10);
	// precision 재설정
	if (option->zero == 1 && option->precision <= -1)
		option->precision = option->width;
	if (option->precision <= -1 || option->precision < num_size)
		option->precision = num_size;
	if (n < 0)
		minus = 1;
	else
		minus = 0;
	if (n == 0 && option->precision == 0)
		ft_putspace(option->width);
	else if (option->left == 0)
	{
		ft_putspace(option->width - option->precision - minus);
		if (minus == 1)
			ft_putchar_fd('-', 1);
		ft_putzero(option->precision - num_size);
		ft_putnbr_fd(n, 1);
	}
	else if (option->left == 1)
	{
		if (minus == 1)
			ft_putchar_fd('-', 1);
		ft_putzero(option->precision - num_size);
		ft_putnbr_fd(n, 1);
		ft_putspace(option->width - option->precision - minus);
	}
	if (n == 0 && option->precision == 0)
		return (option->width);
	else if (option->width > option->precision)
		return (option->width);
	else
		return (option->precision + minus);
}