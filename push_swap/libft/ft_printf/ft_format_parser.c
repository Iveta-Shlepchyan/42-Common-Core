/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 17:17:43 by ishlepch          #+#    #+#             */
/*   Updated: 2026/10/16 17:54:45 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_format	init_format(void)
{
	t_format	format;

	format.left_justify = 0;
	format.zero_padding = 0;
	format.plus_sign = 0;
	format.hash = 0;
	format.space = 0;
	format.width = 0;
	format.precision = -1;
	format.specifier = '\0';
	return (format);
}

static void	parse_flags(const char *str, int *i, t_format *format)
{
	while (str[*i] && ft_strchr("-0+ #", str[*i]))
	{
		if (str[*i] == '-')
			format->left_justify = 1;
		else if (str[*i] == '0')
			format->zero_padding = 1;
		else if (str[*i] == '+')
			format->plus_sign = 1;
		else if (str[*i] == ' ')
			format->space = 1;
		else if (str[*i] == '#')
			format->hash = 1;
		(*i)++;
	}
}

static void	parse_width(const char *str, int *i, t_format *format)
{
	while (ft_isdigit(str[*i]))
	{
		format->width = format->width * 10 + (str[*i] - '0');
		(*i)++;
	}
}

static void	parse_precision(const char *str, int *i, t_format *format)
{
	if (str[*i] == '.')
	{
		(*i)++;
		format->precision = 0;
		while (ft_isdigit(str[*i]))
		{
			format->precision = format->precision * 10 + (str[*i] - '0');
			(*i)++;
		}
	}
}

t_format	parse_format(const char *str, int *i)
{
	t_format	format;

	(*i)++;
	format = init_format();
	parse_flags(str, i, &format);
	parse_width(str, i, &format);
	parse_precision(str, i, &format);
	if (str[*i] && ft_strchr("cspdiuxX%", str[*i]))
	{
		format.specifier = str[*i];
		(*i)++;
	}
	if (format.left_justify)
		format.zero_padding = 0;
	if (format.plus_sign)
		format.space = 0;
	if (format.precision >= 0)
		format.zero_padding = 0;
	return (format);
}
