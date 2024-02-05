/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:03:07 by bbento-a          #+#    #+#             */
/*   Updated: 2023/12/20 12:26:03 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		counter += ft_pnb(va_arg(args, int), 10, counter, format);
	else if (format == 'u')
		counter += ft_pnb(va_arg(args, unsigned int), 10, counter, format);
	else if (format == 'x')
		counter += ft_pnb(va_arg(args, unsigned int), 16, counter, format);
	else if (format == 'X')
		counter += ft_pnb(va_arg(args, unsigned int), 16, counter, format);
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
	return (counter);
}

int	main(void)
{
	char	c = 'c';
	char	*str = NULL;
	int		num = NULL;
	int		hex = num;

	int	res1 = printf("printf: %c %s %d %i %u %x %X %%\n", c, str, num, num, (unsigned int)num, hex, hex);
	int res2 = ft_printf("ft_printf: %c %s %d %i %u %x %X %%\n", c, str, num, num, (unsigned int)num, hex, hex);

	printf("\nprintf res: %d\n", res1);
	printf("res: %d\n", res2);
}
