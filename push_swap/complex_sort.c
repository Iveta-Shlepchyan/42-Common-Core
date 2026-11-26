/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 23:45:14 by ishlepch          #+#    #+#             */
/*   Updated: 2026/11/26 22:39:06 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max_index)
{
	int	bits;

	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

static void	sort_bit(t_stack **a, t_stack **b, t_config *config, int bit)
{
	int	i;
	int	size;

	i = 0;
	size = get_stack_size(*a);
	while (i < size)
	{
		if (((*a)->index >> bit) & 1)
			ra(a, config);
		else
			pb(a, b, config);
		i++;
	}
	while (*b)
		pa(a, b, config);
}

void	radix_sort(t_stack **a, t_stack **b, t_config *config)
{
	int	max_bits;
	int	bit;

	if (get_stack_size(*a) <= 5)
		return (sort_small_input(a, b, config));
	assign_indexes(*a);
	max_bits = get_max_bits(get_stack_size(*a) - 1);
	bit = 0;
	while (bit < max_bits)
	{
		sort_bit(a, b, config, bit);
		bit++;
	}
}
