/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 17:28:56 by ishlepch          #+#    #+#             */
/*   Updated: 2026/11/26 22:41:16 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, t_config *config)
{
	if (!*a || !(*a)->next)
		return ;
	reverse_rotate(a);
	config->ops[RRA]++;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b, t_config *config)
{
	if (!*b || !(*b)->next)
		return ;
	reverse_rotate(b);
	config->ops[RRB]++;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b, t_config *config)
{
	if ((!*a || !(*a)->next) && (!*b || !(*b)->next))
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
	config->ops[RRR]++;
	ft_putstr_fd("rrr\n", 1);
}
