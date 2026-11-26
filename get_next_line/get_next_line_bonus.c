/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 19:55:04 by ishlepch          #+#    #+#             */
/*   Updated: 2026/11/19 20:09:54 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*fail(char **stash, size_t *len, char *buffer)
{
	free(buffer);
	free(*stash);
	*stash = NULL;
	*len = 0;
	return (NULL);
}

static void	clean_stash(char *s, size_t *len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	j = 0;
	while (s[i])
		s[j++] = s[i++];
	s[j] = '\0';
	*len = j;
}

static char	*extract_line(char **stash, size_t *len, char *buffer, int nl)
{
	char	*line;

	line = copy_till(*stash, nl);
	if (nl)
		clean_stash(*stash, len);
	else
	{
		free(*stash);
		*stash = NULL;
		*len = 0;
	}
	free(buffer);
	return (line);
}

static char	*get_buffer(int fd)
{
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	return (malloc(BUFFER_SIZE + 1));
}

char	*get_next_line(int fd)
{
	char			*buffer;
	ssize_t			bytes_read;
	static t_stash	st[OPEN_MAX];

	buffer = get_buffer(fd);
	if (!buffer)
		return (NULL);
	if (check_line_end(st[fd].str))
		return (extract_line(&st[fd].str, &st[fd].len, buffer, 1));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		st[fd].str = stash_join(st[fd].str, buffer, &st[fd].cap, &st[fd].len);
		if (!st[fd].str)
			return (fail(&st[fd].str, &st[fd].len, buffer));
		if (check_line_end(buffer))
			return (extract_line(&st[fd].str, &st[fd].len, buffer, 1));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == 0 && st[fd].str && st[fd].str[0])
		return (extract_line(&st[fd].str, &st[fd].len, buffer, 0));
	return (fail(&st[fd].str, &st[fd].len, buffer));
}
