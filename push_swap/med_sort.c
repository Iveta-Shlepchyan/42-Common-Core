/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 23:44:37 by ishlepch          #+#    #+#             */
/*   Updated: 2026/11/26 22:10:30 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_position(t_stack *s, int target)
{
	int	pos;

	pos = 0;
	while (s)
	{
		if (s->index == target)
			return (pos);
		s = s->next;
		pos++;
	}
	return (-1);
}

static int	chunk_count(int n)
{
	if (n <= 16)
		return (2);
	if (n <= 100)
		return (5);
	return (11);
}


static void	push_chunks_to_b(t_stack **a, t_stack **b, int chunk, t_config *config)
{
	int	pushed;

	pushed = 0;
	while (*a)
	{
		if ((*a)->index <= pushed)
		{
			pb(a, b, config);
			rb(b, config);
			pushed++;
		}
		else if ((*a)->index <= pushed + chunk)
		{
			pb(a, b, config);
			pushed++;
		}
		else
			ra(a, config);
	}
}

static void	push_back_to_a(t_stack **a, t_stack **b, t_config *config)
{
	int	size;
	int	pos;

	size = get_stack_size(*b);
	while (size > 0)
	{
		pos = get_position(*b, size - 1);
		if (pos <= size / 2)
			while (pos-- > 0)
				rb(b, config);
		else
		{
			pos = size - pos;
			while (pos-- > 0)
				rrb(b, config);
		}
		pa(a, b, config);
		size--;
	}
}

void	chunk_sort(t_stack **a, t_stack **b, t_config *config)
{
	int	n;
	int	chunk;

	if (get_stack_size(*a) <= 5)
		return (sort_small_input(a, b, config));
	assign_indexes(*a);
	n = get_stack_size(*a);
	chunk = n / chunk_count(n);
	if (chunk < 1)
		chunk = 1;
	push_chunks_to_b(a, b, chunk, config);
	push_back_to_a(a, b, config);
}
