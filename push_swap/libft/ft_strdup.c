/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:11:25 by ishlepch          #+#    #+#             */
/*   Updated: 2026/06/22 21:11:27 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*sdup;

	len = ft_strlen(s);
	sdup = malloc(len + 1);
	if (!sdup)
		return (NULL);
	ft_strlcpy(sdup, s, len + 1);
	return (sdup);
}
