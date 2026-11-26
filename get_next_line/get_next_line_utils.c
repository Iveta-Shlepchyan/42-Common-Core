/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 20:42:21 by ishlepch          #+#    #+#             */
/*   Updated: 2026/11/19 19:49:47 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	check_line_end(char *str)
{
	if (!str)
		return (0);
	while (*str && *str != '\n')
		str++;
	return (*str == '\n');
}

static char	*grow_stash(char *stash, size_t *cap, size_t len, size_t add)
{
	char	*new_s;
	size_t	i;

	if (!*cap)
		*cap = 32;
	while (*cap < len + add + 1)
		*cap *= 2;
	new_s = malloc(*cap);
	if (!new_s)
	{
		free(stash);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		new_s[i] = stash[i];
		i++;
	}
	free(stash);
	return (new_s);
}

char	*stash_join(char *stash, char *buffer, size_t *cap, size_t *len)
{
	size_t	len_buf;
	size_t	i;

	len_buf = ft_strlen(buffer);
	if (!stash || *cap < *len + len_buf + 1)
		stash = grow_stash(stash, cap, *len, len_buf);
	if (!stash)
		return (NULL);
	i = 0;
	while (buffer[i])
	{
		stash[*len + i] = buffer[i];
		i++;
	}
	*len += len_buf;
	stash[*len] = '\0';
	return (stash);
}

char	*copy_till(char *s, int nl)
{
	size_t	i;
	char	*new_s;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	new_s = malloc(i + 1 + nl);
	if (!new_s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		new_s[i] = s[i];
		i++;
	}
	if (nl)
		new_s[i++] = '\n';
	new_s[i] = '\0';
	return (new_s);
}
