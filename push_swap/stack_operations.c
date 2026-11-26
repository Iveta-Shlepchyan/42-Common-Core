/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 19:26:14 by ishlepch          #+#    #+#             */
/*   Updated: 2026/11/26 19:26:32 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack **src, t_stack **dst)
{
	t_stack	*temp;

	if (!src || !*src)
		return (0);
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
	return (1);
}

int	swap(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return (0);

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	return (1);
}


int	rotate(t_stack **stack)
{
	t_stack	*first;

	if (!stack || !*stack || !(*stack)->next)
		return (0);

	first = *stack;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = first;
	*stack = first->next;
	first->next = NULL;
	return (1);
}


int	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return (0);

	temp = *stack;
	while (temp->next->next)
		temp = temp->next;
	temp->next->next = *stack;
	*stack = temp->next;
	temp->next = NULL;
	return (1);
}

int	add_back(t_stack **stack, t_stack **last, int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	if (!*stack)
		*stack = new_node;
	else
		(*last)->next = new_node;
	*last = new_node;
	return (1);
}
