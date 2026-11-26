/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 19:36:17 by ishlepch          #+#    #+#             */
/*   Updated: 2026/11/26 20:18:03 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_pos(t_stack *s)
{
	int	pos;
	int	min_idx;
	int	min;

	pos = 0;
	min_idx = 0;
	min = s->value;
	while (s)
	{
		if (s->value < min)
		{
			min = s->value;
			min_idx = pos;
		}
		s = s->next;
		pos++;
	}
	return (min_idx);
}

static void	push_min(t_stack **a, t_stack **b, t_config *config)
{
	int	pos;
	int	size;

	pos = min_pos(*a);
	size = get_stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a, config);
	}
	else
	{
		while (pos++ < size)
			rra(a, config);
	}
	pb(a, b, config);
}

static void	sort_three(t_stack **a, t_config *config)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x < y && y < z)
		return ;
	if (x > y && y < z && x < z)
		sa(a, config);
	else if (x > y && y > z)
	{
		sa(a, config);
		rra(a, config);
	}
	else if (x > y && y < z)
		ra(a, config);
	else if (x < y && y > z && x < z)
	{
		sa(a, config);
		ra(a, config);
	}
	else
		rra(a, config);
}

void	sort_small_input(t_stack **a, t_stack **b, t_config *config)
{
	int	size;

	size = get_stack_size(*a);
	if (size < 2 || is_sorted(*a))
		return ;
	if (size == 2)
	{
		sa(a, config);
		return ;
	}
	while (size > 3)
	{
		push_min(a, b, config);
		size--;
	}
	if (!is_sorted(*a))
		sort_three(a, config);
	while (*b)
		pa(a, b, config);
}

