/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 20:42:21 by ishlepch          #+#    #+#             */
/*   Updated: 2026/10/20 20:42:23 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*new_s;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_s = malloc(len_s1 + len_s2 + 1);
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, s1, len_s1 + 1);
	ft_strlcat(new_s, s2, len_s1 + len_s2 + 1);
	return (new_s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}


size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_i;
	size_t	s_i;
	size_t	d_len;

	s_i = 0;
	d_i = 0;
	while (dst[d_i] && d_i < size)
		d_i++;
	d_len = d_i;
	if (size > d_len)
	{
		while (src[s_i] && d_i + 1 < size)
		{
			dst[d_i++] = src[s_i++];
		}
		dst[d_i] = '\0';
	}
	return (d_len + ft_strlen(src));
}
