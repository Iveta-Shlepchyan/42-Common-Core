/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 18:01:29 by ishlepch          #+#    #+#             */
/*   Updated: 2026/10/16 18:01:58 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		argptr;
	t_format	format;
	int			i;
	int			count;

	i = 0;
	count = 0;
	va_start(argptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			format = parse_format(str, &i);
			count += print_formated(format, argptr);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
			count++;
		}
	}
	va_end(argptr);
	return (count);
}

int	print_formated(t_format format, va_list argptr)
{
	if (format.specifier == 'c')
		return (print_char_formated(argptr, format));
	else if (format.specifier == 's')
		return (print_str_formated(argptr, format));
	else if (format.specifier == 'd' || format.specifier == 'i'
		|| format.specifier == 'u')
		return (print_int_formated(argptr, format));
	else if (format.specifier == 'x' || format.specifier == 'X')
		return (print_hex_formated(argptr, format));
	else if (format.specifier == 'p')
		return (print_pointer_formated(argptr, format));
	else if (format.specifier == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}
