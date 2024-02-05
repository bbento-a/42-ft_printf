/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:20:47 by bbento-a          #+#    #+#             */
/*   Updated: 2023/12/22 15:10:52 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_p(unsigned long int ptr)
{
	unsigned long int	temp;
	int					counter;

	counter = 0;
	if (!ptr)
		return (write(1, "(nil)", 5) && 5);
	temp = ptr;
	counter += write(1, "0x", 2);
	ft_pnb(temp, 16, counter, 'p');
	return(counter);
}
