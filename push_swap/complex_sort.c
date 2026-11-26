/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 23:45:14 by ishlepch          #+#    #+#             */
/*   Updated: 2026/11/26 22:14:51 by ishlepch         ###   ########.fr       */
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

void	radix_sort(t_stack **a, t_stack **b, t_config *config)
{
	int	size;
	int	max_bits;
	int	bit;
	int	i;

	if (get_stack_size(*a) <= 5)
		return (sort_small_input(a, b, config));
	assign_indexes(*a);
	size = get_stack_size(*a);
	max_bits = get_max_bits(size - 1);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
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
		bit++;
	}
}
