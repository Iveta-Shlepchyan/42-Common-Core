/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:25:43 by ishlepch          #+#    #+#             */
/*   Updated: 2026/06/23 16:25:45 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	calculate_size(long n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*n_str;
	int		len;
	long	nbr;

	nbr = n;
	len = calculate_size(nbr);
	if (nbr < 0)
		nbr = -nbr;
	n_str = malloc(len + 1);
	if (!n_str)
		return (NULL);
	n_str[len] = '\0';
	if (nbr == 0)
		n_str[0] = '0';
	while (nbr > 0)
	{
		n_str[len - 1] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	if (n < 0)
		n_str[0] = '-';
	return (n_str);
}
