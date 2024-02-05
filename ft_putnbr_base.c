/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:46:27 by bbento-a          #+#    #+#             */
/*   Updated: 2023/12/06 18:25:30 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_pnb(int nbr, char *base) 
{
	char	*hex = "0123456789abcdef";
	int		res;

	if (nbr < 0)
	{
		nbr *= -1;
		res += write(1, "-", 1);
	}
	if (nbr >= base)
		res += ft_pnb(res/)
}
