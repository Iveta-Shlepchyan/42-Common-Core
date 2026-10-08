/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:45:11 by ishlepch          #+#    #+#             */
/*   Updated: 2026/06/22 15:45:12 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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
