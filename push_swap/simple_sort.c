/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 15:36:38 by ishlepch          #+#    #+#             */
/*   Updated: 2026/11/26 22:13:03 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	target_pos(t_stack *b, int val)
{
	int	i;
	int	pos;
	int	best;
	int	max_pos;
	int	max_val;

	i = 0;
	pos = -1;
	max_pos = 0;
	max_val = b->value;
	while (b)
	{
		if (b->value < val && (pos == -1 || b->value > best))
		{
			pos = i;
			best = b->value;
		}
		if (b->value > max_val)
		{
			max_val = b->value;
			max_pos = i;
		}
		i++;
		b = b->next;
	}
	if (pos == -1)
		return (max_pos);
	return (pos);
}

static void	rotate_b_to(t_stack **b, int pos, t_config *config)
{
	int	size;

	size = get_stack_size(*b);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(b, config);
	}
	else
	{
		while (pos++ < size)
			rrb(b, config);
	}
}

void	insertion_sort(t_stack **a, t_stack **b, t_config *config)
{
	if (get_stack_size(*a) <= 5)
		return (sort_small_input(a, b, config));

	if (is_sorted(*a))
		return ;

	while (*a)
	{
		if (*b && (*b)->next)
			rotate_b_to(b, target_pos(*b, (*a)->value), config);
		pb(a, b, config);
	}
	rotate_b_to(b, target_pos(*b, INT_MAX), config);
	while (*b)
		pa(a, b, config);
}


// static int	count_swaps_needed(t_stack *stack_b)
// {
// 	int	count;
// 	int	value;

// 	count = 0;
// 	value = stack_b->value;
// 	while (stack_b->next && (value < (stack_b->next)->value))
// 	{
// 		count++;
// 		stack_b = stack_b->next;
// 	}
// 	if (!stack_b->next)
// 		return (-1);
// 	return (count);
// }

// static void	sb_or_ss(t_stack **stack_a, t_stack **stack_b, t_config *config)
// {
// 	if ((*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
// 		ss(stack_a, stack_b, config);
// 	else
// 		sb(stack_b, config);
// }


// void	insertion_sort(t_stack **stack_a, t_stack **stack_b, t_config *config)
// {
// 	int	s_count;
// 	int	rb_count;

// 	while (*stack_a && (*stack_a)->next)
// 	{
// 		if ((*stack_a)->value > (*stack_a)->next->value)
// 			sa(stack_a, config);
// 		pb(stack_a, stack_b, config);

// 		if ((*stack_b)->next && (*stack_b)->value < (*stack_b)->next->value)
// 		{
// 			s_count = count_swaps_needed(*stack_b);
// 			if (s_count == -1)
// 				rb(stack_b, config);
// 			else
// 			{
// 				rb_count = s_count - 1;
// 				while (s_count > 1)
// 				{
// 					sb_or_ss(stack_a, stack_b, config);
// 					rb(stack_b, config);
// 					s_count--;
// 				}
// 				sb_or_ss(stack_a, stack_b, config);
// 				while (rb_count > 0)
// 				{
// 					rrb(stack_b, config);
// 					rb_count--;
// 				}
// 			}
// 		}
// 	}
// 	while (*stack_b)
// 		pa(stack_a, stack_b, config);
// }