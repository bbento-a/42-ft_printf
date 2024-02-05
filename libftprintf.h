/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:55:46 by bbento-a          #+#    #+#             */
/*   Updated: 2023/12/06 18:21:54 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

// MAIN FUNCTIONS
int	ft_printf(const char *, ...);
int	ft_printf_percent(void);
int	ft_printf_c(char c);


// SUPPORT FUNCTIONS
int	ft_pnb(int nbr, char *base);

#endif
