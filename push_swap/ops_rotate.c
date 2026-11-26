/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 17:29:00 by ishlepch          #+#    #+#             */
/*   Updated: 2026/11/23 17:38:34 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, t_config *config)
{
	if (!rotate(a))
		return ;
	config->ops[RA]++;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b, t_config *config)
{
	if (!rotate(b))
		return ;
	config->ops[RB]++;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b, t_config *config)
{
	if (!rotate(a) && !rotate(b))
		return ;
	config->ops[RR]++;
	ft_putstr_fd("rr\n", 1);
}
