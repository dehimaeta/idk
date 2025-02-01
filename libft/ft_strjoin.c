/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkhas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 01:29:17 by rmalkhas          #+#    #+#             */
/*   Updated: 2025/02/01 01:29:17 by rmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		ls1;
	int		ls2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (!str)
		return (NULL);
	ft_memmove(str, s1, ls1);
	ft_memmove(str + ls1, s2, ls2);
	str[ls1 + ls2] = '\0';
	return (str);
}
