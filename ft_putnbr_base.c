/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:46:27 by bbento-a          #+#    #+#             */
/*   Updated: 2023/12/18 12:27:30 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_pnb(int nbr, char *base, int len)
{
	int		res;
	int		counter;

	counter = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		counter += ft_printf_c('-');
	}
	if (nbr >= len)
		ft_pnb(res / len, base, len);
	counter += ft_printf_c(base[res % len]);
	return (counter);
}
