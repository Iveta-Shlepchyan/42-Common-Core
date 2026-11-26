/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 17:20:12 by ishlepch          #+#    #+#             */
/*   Updated: 2026/11/26 20:18:46 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(double disorder)
{
	int	value;

	value = (int)(disorder * 10000 + 0.5);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(value / 100, 2);
	ft_putchar_fd('.', 2);
	if (value % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(value % 100, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_count(char *name, int count)
{
	ft_putstr_fd(name, 2);
	ft_putnbr_fd(count, 2);
	ft_putchar_fd(' ', 2);
}

static void	print_operations(t_config *config)
{
	ft_putstr_fd("[bench] ", 2);
	print_count("sa: ", config->ops[SA]);
	print_count("sb: ", config->ops[SB]);
	print_count("ss: ", config->ops[SS]);
	print_count("pa: ", config->ops[PA]);
	print_count("pb: ", config->ops[PB]);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] ", 2);
	print_count("ra: ", config->ops[RA]);
	print_count("rb: ", config->ops[RB]);
	print_count("rr: ", config->ops[RR]);
	print_count("rra: ", config->ops[RRA]);
	print_count("rrb: ", config->ops[RRB]);
	print_count("rrr: ", config->ops[RRR]);
	ft_putchar_fd('\n', 2);
}

static void	print_strategy(t_strategy strategy, double disorder)
{
	if (strategy == SIMPLE)
		ft_putstr_fd("Simple / O(n^2)\n", 2);
	else if (strategy == MEDIUM)
		ft_putstr_fd("Medium / O(n√n)\n", 2);
	else if (strategy == COMPLEX)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else if (disorder < 0.2)
		ft_putstr_fd("Adaptive / O(n^2)\n", 2);
	else if (disorder < 0.5)
		ft_putstr_fd("Adaptive / O(n√n)\n", 2);
	else
		ft_putstr_fd("Adaptive / O(n log n)\n", 2);
}

void	print_benchmark(t_config *config, double disorder)
{
	if (!config->bench)
		return ;
	print_disorder(disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	print_strategy(config->strategy, disorder);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(get_total_operations(config), 2);
	ft_putchar_fd('\n', 2);
	print_operations(config);
}