/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 18:01:29 by ishlepch          #+#    #+#             */
/*   Updated: 2026/10/08 18:01:30 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list argptr;
	va_start(argptr, str);
	int	i;
	int	a_i;

	i = 0;
	a_i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i+1] == 'c')
				ft_putchar_fd((char)va_arg(argptr, int), 1);
			else if (str[i+1] == 's')
				ft_putstr_fd(va_arg(argptr, char*), 1);
			else if (str[i+1] == 'd' || str[i+1] == 'i')
				ft_putnbr_fd(va_arg(argptr, int), 1);
			a_i++;
			i += 2; 
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
		
	}
	va_end(argptr);
	return (0);
}
