/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkhas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:27:11 by rmalkhas          #+#    #+#             */
/*   Updated: 2025/02/17 17:27:11 by rmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_putchar(char a);
int	ft_putstr(char *str);
int	ft_puthex(unsigned long long nbr, int uppercase);
int	ft_putptr(unsigned long long nbr);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putnbr(int n);
int	ft_printf(const char *str, ...);

#endif
