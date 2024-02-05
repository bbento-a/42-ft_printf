/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:31:47 by bbento-a          #+#    #+#             */
/*   Updated: 2023/12/20 12:25:44 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(char *s)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		res += write(1, &s[i], 1);
		i++;
	}
	return (res);
}
