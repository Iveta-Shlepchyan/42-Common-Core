/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 17:26:25 by ishlepch          #+#    #+#             */
/*   Updated: 2026/11/23 17:41:09 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, t_config *config)
{
	if (!swap(a))
		return ;
	config->ops[SA]++;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b, t_config *config)
{
	if (!swap(b))
		return ;
	config->ops[SB]++;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b, t_config *config)
{
	if (!swap(a) && !swap(b))
		return ;
	config->ops[SS]++;
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_stack **a, t_stack **b, t_config *config)
{
	if (!push(b, a))
		return ;
	config->ops[PA]++;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **a, t_stack **b, t_config *config)
{
	if (!push(a, b))
		return ;
	config->ops[PB]++;
	ft_putstr_fd("pb\n", 1);
}
