/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:07:34 by bokim             #+#    #+#             */
/*   Updated: 2021/07/06 17:13:09 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_option(t_opt *option)
{
	option->left = 0;
	option->zero = 0;
	option->width = 0;
	option->dot = 0;
	option->precision = -1;
	option->type = 0;
}

int		ft_control(va_list ap, char *input)
{
	t_opt	*option;
	int		cnt;
	int		*idx;

	cnt = 0;
	option = (t_opt *)malloc(sizeof(t_opt));
	if (!option)
		return (-1);
	idx = &(option->index);
	*idx = 0;
	while (input[*idx] != '\0')
	{
		while (input[*idx] != '%' && input[*idx] != '\0')
		{
			cnt += ft_putchar(input[*idx], 1);
			*idx += 1;
		}
		if (input[*idx] == '%' && input[*idx] != '\0')
		{
			ft_init_option(option);
			*idx += 1;
			cnt += ft_parse(input, option, ap);
		}
	}
	free(option);
	return (cnt);
}

int		ft_printf(const char *input, ...)
{
	va_list	ap;
	int		ret;
	
	va_start(ap, input);
	ret = ft_control(ap, (char *)input);
	va_end(ap);
	return (ret);
}