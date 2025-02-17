/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkhas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:04:18 by rmalkhas          #+#    #+#             */
/*   Updated: 2025/02/17 18:04:18 by rmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long nbr, int uppercase)
{
	char	*base;
	int		len;

	len = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr >= 16)
		len += ft_puthex(nbr / 16, uppercase);
	len += ft_putchar(base[nbr % 16]);
	return (len);
}

int	ft_putptr(unsigned long long nbr)
{
	int	len;

	len = 0;
	if (!nbr)
		return (write(1, "0x0", 3));
	len += ft_putstr("0x");
	len += ft_puthex(nbr, 0);
	return (len);
}
