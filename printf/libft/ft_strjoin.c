/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:03:28 by ishlepch          #+#    #+#             */
/*   Updated: 2026/06/23 14:03:29 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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
