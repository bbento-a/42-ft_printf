/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:03:07 by bbento-a          #+#    #+#             */
/*   Updated: 2023/12/18 12:11:52 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_format_flags(va_list args, const char format)
{
	int	counter;

	counter = 0;
	if (format == '%')
		counter += ft_printf_percent();
	else if (format == 'c')
		counter += ft_printf_c(va_arg(args, int));
	else if (format == 's')
		counter += ft_printf_s(va_arg(args, char *));
	//else if (format == 'p')
	//	counter += ft_printf_p(va_arg(args, unsigned int));
	else if (format == 'd' || format == 'i')
		counter += ft_pnb(va_arg(args, int), "0123456789", 10);
	else if (format == 'u')
		counter += ft_pnb(va_arg(args, unsigned int), "0123456789", 10);
	else if (format == 'x')
		counter += ft_pnb(va_arg(args, unsigned int), "0123456789abcdef", 16);
	else if (format == 'X')
		counter += ft_pnb(va_arg(args, unsigned int), "0123456789ABCDEF", 16);
	return (counter);
}

int	ft_printf(const char *s, ...)
{
	int		counter;
	int		i;
	va_list	args;

	va_start(args, s);
	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			counter += ft_format_flags(args, s[i + 1]);
			i++;
		}
		else
			counter += ft_printf_c(s[i]);
		i++;
	}
	va_end(args);
	return (0);
}
