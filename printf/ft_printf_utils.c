/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 17:09:52 by ishlepch          #+#    #+#             */
/*   Updated: 2026/10/17 03:07:06 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_padding(int pad_len, char pad_char)
{
	while (pad_len-- > 0)
		ft_putchar_fd(pad_char, 1);
}

void	print_hex(unsigned long n, int upper)
{
	char	*digits;

	if (upper)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (n / 16 > 0)
		print_hex(n / 16, upper);
	ft_putchar_fd(digits[n % 16], 1);
}

int	count_digits(unsigned long n, int base)
{
	int	count;

	count = 1;
	while (n / base > 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
