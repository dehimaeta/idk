/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfatil.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkhas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:24:57 by rmalkhas          #+#    #+#             */
/*   Updated: 2025/02/17 17:24:57 by rmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char a)
{
	return (write (1, &a, 1));
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
		len += ft_putchar(*str++);
	return (len);
}

int	ft_putnbr(int n)
{
	char	num;
	long	nbr;
	int		len;

	nbr = n;
	len = 0;
	if (nbr < 0)
	{
		len += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		len += ft_putnbr(nbr / 10);
	num = nbr % 10 + '0';
	len += ft_putchar(num);
	return (len);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	char	num;
	int		len;

	len = 0;
	if (n >= 10)
		len += ft_putnbr_unsigned(n / 10);
	num = n % 10 + '0';
	len += ft_putchar(num);
	return (len);
}
