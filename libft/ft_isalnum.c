/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkhas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 03:10:09 by rmalkhas          #+#    #+#             */
/*   Updated: 2024/12/03 03:10:09 by rmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int n)
{
	if ((n >= 'A' && n <= 'Z') || (n >= 'a' && n <= 'z')
		|| (n >= '0' && n <= '9'))
	{
		return (1);
	}
	return (0);
}
