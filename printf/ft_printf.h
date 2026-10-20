/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 18:05:25 by ishlepch          #+#    #+#             */
/*   Updated: 2026/10/17 02:53:18 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_format
{
	int		left_justify;
	int		zero_padding;
	int		plus_sign;
	int		hash;
	int		space;
	int		width;
	int		precision;
	char	specifier;
}	t_format;

int			ft_printf(const char *str, ...);
t_format	parse_format(const char *str, int *i);
int			print_formated(t_format format, va_list argptr);
int			print_char_formated(va_list argptr, t_format format);
int			print_str_formated(va_list argptr, t_format format);
int			print_int_formated(va_list argptr, t_format format);
int			print_hex_formated(va_list argptr, t_format format);
int			print_pointer_formated(va_list argptr, t_format format);

void		print_padding(int pad_len, char pad_char);
void		print_hex(unsigned long n, int upper);
int			count_digits(unsigned long n, int base);
int			ft_min(int a, int b);

#endif
