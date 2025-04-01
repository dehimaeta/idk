/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkhas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:21:00 by rmalkhas          #+#    #+#             */
/*   Updated: 2025/02/21 18:21:00 by rmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	readline(int fd, char **str)
{
	char	*buf;
	int		bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return ;
	while (1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(*str);
			*str = NULL;
			break ;
		}
		buf[bytes] = '\0';
		if (bytes == 0)
			break ;
		*str = ft_strjoin(*str, buf);
		if (ft_strchr(*str, '\n'))
			break ;
	}
	free(buf);
}

char	*ft_remainder(char *str)
{
	char	*remainder;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	remainder = (char *)malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!remainder)
		return (NULL);
	j = 0;
	while (str[++i])
		remainder[j++] = str[i];
	remainder[j] = 0;
	free(str);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	readline(fd, &str);
	s = ft_cutstr(str);
	if (s && !*s)
	{
		free(s);
		free(str);
		str = NULL;
		s = NULL;
		return (NULL);
	}
	str = ft_remainder(str);
	return (s);
}

int main(void)
{
	char *line;

	int fd = open("get_next_line.c", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	return (0);
}