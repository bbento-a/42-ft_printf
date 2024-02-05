/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:55:46 by bbento-a          #+#    #+#             */
/*   Updated: 2023/12/19 11:44:01 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

// MAIN FUNCTIONS
int	ft_printf(const char *s, ...);
int	ft_printf_percent(void);
int	ft_printf_c(char c);
int	ft_printf_s(char *s);
// SUPPORT FUNCTIONS
int	ft_pnb(int nbr, char *base, int len);

#endif
