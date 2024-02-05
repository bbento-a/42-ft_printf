/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:46:27 by bbento-a          #+#    #+#             */
/*   Updated: 2023/12/20 12:22:56 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pnb(long long int nbr, int base, int counter, char flag)
{
	char	*hexa_min = "0123456789abcdef";
	char	*hexa_max = "0123456789ABCDEF";

	if (nbr < 0)
	{
		nbr *= -1;
		counter += write(1, "-", 1);
	}
	if (nbr > base)
		ft_pnb((nbr / base), base, counter, flag);
	if (flag != 'X')
		counter += write(1, &hexa_min[nbr % base], 1);
	else
		counter += write(1, &hexa_max[nbr % base], 1);
	return (counter);
}
