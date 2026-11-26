/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 20:41:56 by ishlepch          #+#    #+#             */
/*   Updated: 2026/11/19 20:16:10 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	return (malloc(BUFFER_SIZE + 1));
}

char	*get_next_line(int fd)
{
	char			*buffer;
	ssize_t			bytes_read;
	static char		*stash;
	static size_t	cap;
	static size_t	len;

	buffer = get_buffer(fd);
	if (!buffer)
		return (NULL);
	if (check_line_end(stash))
		return (extract_line(&stash, &len, buffer, 1));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		stash = stash_join(stash, buffer, &cap, &len);
		if (!stash)
			return (fail(&stash, &len, buffer));
		if (check_line_end(buffer))
			return (extract_line(&stash, &len, buffer, 1));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == 0 && stash && stash[0])
		return (extract_line(&stash, &len, buffer, 0));
	return (fail(&stash, &len, buffer));
}

// char *get_next_line(int fd)
// {
// 	char			*buffer;
// 	char			*line;
// 	ssize_t 		bytes_read;
// 	static char		*stash;
// 	static size_t	stash_capacity;
// 	static size_t 	stash_len;

// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
//     	return (NULL);

// 	buffer = malloc(BUFFER_SIZE + 1);
// 	if (!buffer)
// 		return (NULL);

// 	if (!stash)
// 	{
// 		stash_capacity = 32;
// 		stash_len = 0;
// 		stash = malloc(stash_capacity);
// 		if (!stash)
// 		{
// 			free(buffer);
// 			return (NULL);
// 		}
// 		stash[0] = '\0';
// 	}

// 	if (check_line_end(stash))
// 	{
// 		line = copy_till(stash, 1);
// 		clean_stash(stash);
// 		free(buffer);
// 		return (line);
// 	}

// 	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
// 	{
// 		buffer[bytes_read] = '\0';
// 		stash_len += bytes_read;
// 		stash = stash_join(stash, buffer, &stash_capacity, &stash_len);
// 		if (check_line_end(buffer))
// 		{
// 			line = copy_till(stash, 1);
// 			clean_stash(stash);
// 			free(buffer);
// 			return (line);
// 		}
// 	}

// 	if (bytes_read == 0 && stash[0])
// 	{
// 		line = copy_till(stash, 0);
// 		free(stash);
// 		stash = NULL;
// 		free(buffer);
// 		return (line);
// 	}
// 	free(buffer);
// 	return (NULL);
// }