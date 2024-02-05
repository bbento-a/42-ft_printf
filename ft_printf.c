/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:03:07 by bbento-a          #+#    #+#             */
/*   Updated: 2023/12/26 10:54:44 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_flags(va_list args, const char format)
{
	int	counter;

	counter = 0;
	if (format == '%')
		counter += ft_printf_c('%');
	else if (format == 'c')
		counter += ft_printf_c(va_arg(args, int));
	else if (format == 's')
		counter += ft_printf_s(va_arg(args, char *));
	else if (format == 'p')
		counter += ft_printf_p(va_arg(args, unsigned long int));
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
	char	*str = "Testing";
	int		num = -69420;
	int		hex = num;
	char	*nulstr = NULL;
	void	*ptr = NULL;

	printf("\nXXXXXXXXXX  Test 1  XXXXXXXXXX\n");

	printf("\nPrintf\n");
	int	res1 = printf("%c %s %p %d %i %u %x %X %%\n", c, str, str, num, num, \
	(unsigned int)num, hex, hex);
	printf("\nFt_printf\n");
	int res2 = ft_printf("%c %s %p %d %i %u %x %X %%\n", c, str, str, num, num\
	, (unsigned int)num, hex, hex);

	printf("\nPrintf pointers: %p %p %p %p\n", &c, str, &num, &hex);
	ft_printf("\nFt_printf pointers: %p %p %p %p\n", &c, str, &num, &hex);

	printf("\nPrintf nulls: %s %p\n", nulstr, ptr);
	ft_printf("\nFt_printf nulls: %s %p\n", nulstr, ptr);


	printf("\nXXXXXXXXXX  Test 2  XXXXXXXXXX\n");
	printf("\nprintf res: %d\n", res1);
	printf("res: %d\n", res2);

	printf("\nTest c\n");
	int r1 = printf("%c\n", c);
	int r2 = ft_printf("%c\n", c);
	printf("printf %%c result: %d\n", r1);
	printf("ft_ %%c result: %d\n", r2);

	printf("\nTest s\n");
	int r3 = printf("%s\n", str);
	int r4 = ft_printf("%s\n", str);
	printf("printf %%s result: %d\n", r3);
	printf("ft_ %%s result: %d\n", r4);

	printf("\nTest p\n");
	int r5 = printf("%p\n", str);
	int r6 = ft_printf("%p\n", str);
	printf("printf %%p result: %d\n", r5);
	printf("ft_ %%p result: %d\n", r6);

	printf("\nTest d\n");
	int r7 = printf("%d\n", num);
	int r8 = ft_printf("%d\n", num);
	printf("printf %%d result: %d\n", r7);
	printf("ft_ %%d result: %d\n", r8);

	printf("\nTest i\n");
	int r9 = printf("%i\n", num);
	int r10 = ft_printf("%i\n", num);
	printf("printf %%i result: %d\n", r9);
	printf("ft_ %%i result: %d\n", r10);

	printf("\nTest u\n");
	int r11 = printf("%u\n", (unsigned int)num);
	int r12 = ft_printf("%u\n", (unsigned int)num);
	printf("printf %%u result: %d\n", r11);
	printf("ft_ %%u result: %d\n", r12);

	printf("\nTest x\n");
	int r13 = printf("%x\n", hex);
	int r14 = ft_printf("%x\n", hex);
	printf("printf %%x result: %d\n", r13);
	printf("ft_ %%x result: %d\n", r14);

	printf("\nTest X\n");
	int r15 = printf("%X\n", hex);
	int r16 = ft_printf("%X\n", hex);
	printf("printf %%X result: %d\n", r15);
	printf("ft_ %%X result: %d\n", r16);

	printf("\nTest %%\n");
	int r17 = printf("%%\n");
	int r18 = ft_printf("%%\n");
	printf("printf %% result: %d\n", r17);
	printf("ft_ %% result: %d\n", r18);
}

