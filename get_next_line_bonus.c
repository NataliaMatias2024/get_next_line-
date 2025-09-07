/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:27:49 by namatias          #+#    #+#             */
/*   Updated: 2025/09/07 16:18:18 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_text(int fd, char *text, char **saving)
{
	char		*helper;
	ssize_t		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, text, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		if (bytes_read == 0)
			return (saving[fd]);
		text[bytes_read] = '\0';
		helper = saving[fd];
		saving[fd] = ft_strjoin(helper, text);
		free(helper);
		if (ft_strchr(saving[fd], '\n'))
			return (saving[fd]);
	}
	return (saving[fd]);
}

char	*extract_line(char *new_line)
{
	int		i;
	char	*helper;

	if (!new_line)
		return (NULL);
	i = 0;
	while (new_line[i] != '\n' && new_line[i] != '\0')
		i++;
	if (new_line[i] == '\n')
		i++;
	if (new_line[i] == '\0')
		helper = ft_strdup(new_line);
	else
		helper = ft_substr(new_line, 0, i);
	return (helper);
}

char	*extract_rest(char *new_line)
{
	int		i;
	int		j;
	char	*helper;

	i = 0;
	helper = NULL;
	while (new_line[i] != '\n' && new_line[i] != '\0')
		i++;
	if (new_line[i] == '\n' && new_line[i + 1] != '\0')
	{
		j = ft_strlen(new_line);
		helper = ft_substr(new_line, i + 1, j - (i+1));
	}
	return (helper);
}

char	*get_next_line(int fd)
{
	char		*text;
	char		*new_line;
	char		*line;
	static char	*saving[MAX_FD];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
	{
		free (saving[fd]);
		saving[fd] = NULL;
		return (NULL);
	}
	text = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!text)
		return (NULL);
	new_line = read_text(fd, text, saving);
	free (text);
	if (!new_line)
	{
		free(saving[fd]);
		saving[fd] = NULL;
		return (NULL);
	}
	line = extract_line(new_line);
	saving[fd] = extract_rest(new_line);
	if (new_line != NULL && new_line != saving[fd])
		free(new_line);
	return (line);
}
