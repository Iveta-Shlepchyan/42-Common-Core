/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_formatter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 02:12:35 by ishlepch          #+#    #+#             */
/*   Updated: 2026/10/17 02:24:43 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_pointer_value(unsigned long n)
{
	if (!n)
		ft_putstr_fd("(nil)", 1);
	else
	{
		ft_putstr_fd("0x", 1);
		print_hex(n, 0);
	}
}

static void	print_pointer_with_padding(unsigned long n,
		t_format format, int w_padding)
{
	if (format.left_justify)
	{
		print_pointer_value(n);
		print_padding(w_padding, ' ');
	}
	else
	{
		print_padding(w_padding, ' ');
		print_pointer_value(n);
	}
}

int	print_pointer_formated(va_list argptr, t_format format)
{
	void			*ptr;
	unsigned long	n;
	int				len;
	int				w_padding;

	ptr = va_arg(argptr, void *);
	n = (unsigned long)ptr;
	if (!n)
		len = 5;
	else
		len = count_digits(n, 16) + 2;
	w_padding = format.width - len;
	if (w_padding < 0)
		w_padding = 0;
	print_pointer_with_padding(n, format, w_padding);
	return (w_padding + len);
}
