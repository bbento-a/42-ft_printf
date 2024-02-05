/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:20:47 by bbento-a          #+#    #+#             */
/*   Updated: 2023/12/23 13:00:05 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p(unsigned long int ptr)
{
	int	counter;

	counter = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	counter += write(1, "0x", 2);
	counter += ft_pnb(ptr, 16, 0, 'p');
	return (counter);
}
