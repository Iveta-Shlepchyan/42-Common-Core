/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_formatter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 18:06:32 by ishlepch          #+#    #+#             */
/*   Updated: 2026/10/17 03:04:45 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putnbr_unsigned(unsigned int n, int fd)
{
	long	l;

	l = n;
	if (l < 0)
	{
		ft_putchar_fd('-', fd);
		l *= -1;
	}
	if (l > 9)
		ft_putnbr_fd(l / 10, fd);
	ft_putchar_fd(l % 10 + '0', fd);
}

static unsigned int	get_int_value(va_list argptr, t_format format,
		char *sign)
{
	long	n;

	if (format.specifier == 'u')
		return (va_arg(argptr, unsigned int));
	n = va_arg(argptr, int);
	if (n < 0)
	{
		*sign = '-';
		n = -n;
	}
	else if (format.plus_sign)
		*sign = '+';
	else if (format.space)
		*sign = ' ';
	return (n);
}

static void	print_sign_and_padding(t_format format, char sign,
		int p_padding, int w_padding)
{
	if (!format.left_justify
		&& !(format.zero_padding && format.precision == -1))
		print_padding(w_padding, ' ');
	if (sign)
		ft_putchar_fd(sign, 1);
	if (!format.left_justify && format.zero_padding
		&& format.precision == -1)
		print_padding(w_padding, '0');
	else
		print_padding(p_padding, '0');
}

static int	print_int_value(unsigned long n, t_format format, char sign)
{
	int	len;
	int	p_padding;
	int	w_padding;

	len = count_digits(n, 10);
	if (n == 0 && format.precision == 0)
		len = 0;
	p_padding = 0;
	if (format.precision > len)
		p_padding = format.precision - len;
	w_padding = format.width - len - p_padding - (sign != '\0');
	if (w_padding < 0)
		w_padding = 0;
	print_sign_and_padding(format, sign, p_padding, w_padding);
	if (len > 0)
		putnbr_unsigned(n, 1);
	if (format.left_justify)
		print_padding(w_padding, ' ');
	return (w_padding + p_padding + len + (sign != '\0'));
}

int	print_int_formated(va_list argptr, t_format format)
{
	unsigned long	n;
	char			sign;

	sign = '\0';
	n = get_int_value(argptr, format, &sign);
	return (print_int_value(n, format, sign));
}
