/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkhas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:30:27 by rmalkhas          #+#    #+#             */
/*   Updated: 2025/03/27 19:30:27 by rmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*fill_storage(int fd, char *storage, char *buffer)
{
	ssize_t	bytes;
	char	*temp;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		else if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		temp = storage;
		storage = ft_strjoin(temp, buffer);
		if (!storage)
		{
			free(temp);
			temp = NULL;
			return (NULL);
		}
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (storage);
}

static char	*update_storage(char *final_line)
{
	char	*updated;
	ssize_t	i;

	if (!final_line)
		return (NULL);
	i = 0;
	while (final_line[i] && final_line[i] != '\n' && final_line[i] != '\0')
		i++;
	if (final_line[i] == '\0' || final_line[i + 1] == '\0')
		return (NULL);
	updated = ft_substr(final_line, i + 1, ft_strlen(final_line) - i);
	if (!updated)
		return (NULL);
	final_line[i + 1] = '\0';
	if (*updated == '\0')
		updated = NULL;
	return (updated);
}

char	*get_next_line(int fd)
{
	static char	*storage[FOPEN_MAX];
	char		*final_line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) || fd > FOPEN_MAX)
	{
		free(buffer);
		free(storage[fd]);
		buffer = NULL;
		storage[fd] = NULL;
		return (NULL);
	}
	final_line = fill_storage(fd, storage[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!final_line || *final_line == '\0')
	{
		free(final_line);
		return (NULL);
	}
	storage[fd] = update_storage(final_line);
	return (final_line);
}
