/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:03:07 by bbento-a          #+#    #+#             */
/*   Updated: 2023/11/23 16:57:18 by bbento-a         ###   ########.fr       */
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
		counter += ft_printf_c(va_arg(args, char));
	return (counter);
}

int	ft_printf(const char *s, ...)
{
	int		counter;
	int		i;
	va_list args;

	va_start(args, count);
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
