/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkhas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:35:23 by rmalkhas          #+#    #+#             */
/*   Updated: 2025/01/31 21:35:23 by rmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*calloc(size_t count, size_t size)
{
	char	*arr;

	if ((size != 0 && count > 65536) || (size > 65536 && count != 0))
		return (NULL);
	arr = malloc(size * count);
	if (!arr)
		return (NULL);
	ft_bzero(arr, count);
	return (arr);
}
