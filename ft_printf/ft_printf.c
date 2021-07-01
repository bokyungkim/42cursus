/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:07:34 by bokim             #+#    #+#             */
/*   Updated: 2021/07/01 22:43:50 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_option(t_opt *option)
{
	option->minus = 0;
	option->zero = 0;
	option->width = 0;
	option->star = 0;
	option->dot = 0;
	option->precision = -1;
	option->type = 0;
}

void	ft_parse_flag(char c, t_opt *option)
{
	if (c == '-')
		option->minus = 1;
	else if (c == '0')
		option->zero = 1;
	else if (c == '.')
		option->dot = 1;
	else
		option->star = 1;
	if (option->minus == 1 && option->zero == 1)
		option->zero = 0;
}

int		ft_parse(char *input, t_opt *option, va_list ap)
{
	int		ret;
	int		index;

	ret = 0;
	index = 0;
	while (input && !ft_strchr(CONVERSION, input[index]))
	{
		if (ft_strchr(FLAG, input[index]))
			ft_parse_flag(input[index], option);
		if (ft_strchr(DIGIT, input[index]))
		index++;
	}
}

int		ft_control(va_list ap, char *input)
{
	t_opt	*option;
	int		ret;
	int		index;
	int		parsed;

	ret = 0;
	index = 0;
	option = (t_opt *)malloc(sizeof(t_opt));
	if (!option)
		return (-1);
	while (input[index] != '\0')
	{
		parsed = 0;
		while (input[index] != '%' && input[index] != '\0')
		{
			ret += ft_putchar(input[index], 1);
			index += 1;
		}
		if (input[index] == '%' && input[index] != '\0')
		{
			ft_init_option(option);
			parsed = ft_parse(input + index + 1, option, ap);
			ret += parsed;
			index += parsed; //값 확인 필요
		}
	}
	free(option);
	return (ret);
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