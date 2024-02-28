/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-yag <yben-yag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 13:44:54 by yben-yag          #+#    #+#             */
/*   Updated: 2024/02/16 13:04:20 by yben-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/get_next_line_bonus.h"

static char	*set_extracted_content(char *line_buffer)
{
	char	*extracted_content;
	ssize_t	i;

	i = 0;
	extracted_content = NULL;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0)
		return (0);
	extracted_content = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer));
	if (*extracted_content == 0)
	{
		free(extracted_content);
		extracted_content = NULL;
	}
	line_buffer[i + 1] = 0;
	return (extracted_content);
}

static char	*fill_line_buffer(int fd, char *remaining_buffer, char *read_buffer)
{
	ssize_t	bytes_read;
	char	*temporary_buffer;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(remaining_buffer);
			return (NULL);
		}
		else if (bytes_read == 0)
			return (remaining_buffer);
		read_buffer[bytes_read] = 0;
		if (!remaining_buffer)
			remaining_buffer = ft_strdup("");
		temporary_buffer = remaining_buffer;
		remaining_buffer = ft_strjoin(temporary_buffer, read_buffer);
		free(temporary_buffer);
		temporary_buffer = NULL;
		if (ft_strchr(read_buffer, '\n'))
			return (remaining_buffer);
	}
	return (remaining_buffer);
}

char	*ft_strchr(const char *s, int c)
{
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (c % 256 == *s++)
			return ((char *)s - 1);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*remaining_buffer[MAX_FD];
	char		*current_line;
	char		*read_buffer;

	read_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || MAX_FD > 4096)
	{
		free(read_buffer);
		return (NULL);
	}
	if (!read_buffer)
		return (NULL);
	current_line = fill_line_buffer(fd, remaining_buffer[fd], read_buffer);
	free(read_buffer);
	if (!current_line)
		return (NULL);
	remaining_buffer[fd] = set_extracted_content(current_line);
	return (current_line);
}
