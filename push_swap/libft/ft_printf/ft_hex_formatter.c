/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_formatter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 18:06:54 by ishlepch          #+#    #+#             */
/*   Updated: 2026/10/17 02:19:41 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_hex_prefix(unsigned int n, t_format format)
{
	if (format.hash && n != 0)
	{
		if (format.specifier == 'X')
			return ("0X");
		return ("0x");
	}
	return ("");
}

static int	get_hex_length(unsigned int n, t_format format)
{
	int	len;

	len = count_digits(n, 16);
	if (n == 0 && format.precision == 0)
		len = 0;
	return (len);
}

static void	print_hex_prefix_padding(char *prefix, t_format format,
		int p_padding, int w_padding)
{
	if (format.left_justify)
	{
		ft_putstr_fd(prefix, 1);
		print_padding(p_padding, '0');
	}
	else if (format.zero_padding && format.precision == -1)
	{
		ft_putstr_fd(prefix, 1);
		print_padding(w_padding, '0');
	}
	else
	{
		print_padding(w_padding, ' ');
		ft_putstr_fd(prefix, 1);
		print_padding(p_padding, '0');
	}
}

int	print_hex_formated(va_list argptr, t_format format)
{
	unsigned int	n;
	int				len;
	int				p_padding;
	int				w_padding;
	char			*prefix;

	n = va_arg(argptr, unsigned int);
	len = get_hex_length(n, format);
	prefix = get_hex_prefix(n, format);
	p_padding = 0;
	if (format.precision > len)
		p_padding = format.precision - len;
	w_padding = format.width - len - p_padding - ft_strlen(prefix);
	if (w_padding < 0)
		w_padding = 0;
	print_hex_prefix_padding(prefix, format, p_padding, w_padding);
	if (len > 0)
		print_hex(n, format.specifier == 'X');
	if (format.left_justify)
		print_padding(w_padding, ' ');
	return (w_padding + p_padding + len + ft_strlen(prefix));
}
