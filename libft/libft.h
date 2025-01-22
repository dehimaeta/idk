/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkhas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:21:43 by rmalkhas          #+#    #+#             */
/*   Updated: 2024/12/06 23:21:43 by rmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_isalpha(int alph);
int		ft_isdigit(int num);
int		ft_isalnum(int n);
int		ft_isascii(int ascii);
int		ft_isprint(int p);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *str, int c, size_t len);
void	ft_bzero(void *str, size_t len);
int		ft_atoi(const char *str);
void	*ft_memcpy(void *dst, void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);

#endif
