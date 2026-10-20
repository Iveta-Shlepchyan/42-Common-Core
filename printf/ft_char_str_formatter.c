/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_str_formatter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 17:05:25 by ishlepch          #+#    #+#             */
/*   Updated: 2026/10/17 03:06:56 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char_formated(va_list argptr, t_format format)
{
	char	c;
	int		padding;

	c = (char)va_arg(argptr, int);
	padding = format.width - 1;
	if (padding < 0)
		padding = 0;
	if (format.left_justify)
	{
		ft_putchar_fd(c, 1);
		print_padding(padding, ' ');
	}
	else
	{
		print_padding(padding, ' ');
		ft_putchar_fd(c, 1);
	}
	return (1 + padding);
}

static void	print_str_till(char *s, int precision)
{
	int	i;

	i = 0;
	while (s[i] && i < precision)
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
}

static char	*get_printable_string(char *s, int precision)
{
	if (s)
		return (s);
	if (precision >= 0 && precision < 6)
		return ("");
	return ("(null)");
}

int	print_str_formated(va_list argptr, t_format format)
{
	char	*s;
	int		len;
	int		padding;

	s = va_arg(argptr, char *);
	s = get_printable_string(s, format.precision);
	len = ft_strlen(s);
	if (format.precision >= 0)
		len = ft_min(len, format.precision);
	padding = format.width - len;
	if (padding < 0)
		padding = 0;
	if (format.left_justify)
	{
		print_str_till(s, len);
		print_padding(padding, ' ');
	}
	else
	{
		print_padding(padding, ' ');
		print_str_till(s, len);
	}
	return (len + padding);
}
