/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <ishlepch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 19:21:21 by ishlepch          #+#    #+#             */
/*   Updated: 2026/11/27 21:21:05 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	do_operation(char *op, t_stack **a, t_stack **b,
		t_config *config)
{
	int	len;

	len = ft_strlen(op);
	if (len > 0 && op[len - 1] == '\n')
		op[len - 1] = '\0';
	if (!ft_strncmp(op, "sa", 3))
		sa(a, config);
	else if (!ft_strncmp(op, "sb", 3))
		sb(b, config);
	else if (!ft_strncmp(op, "ss", 3))
		ss(a, b, config);
	else if (!ft_strncmp(op, "pa", 3))
		pa(a, b, config);
	else if (!ft_strncmp(op, "pb", 3))
		pb(a, b, config);
	else if (!ft_strncmp(op, "ra", 3))
		ra(a, config);
	else if (!ft_strncmp(op, "rb", 3))
		rb(b, config);
	else if (!ft_strncmp(op, "rr", 3))
		rr(a, b, config);
	else if (!ft_strncmp(op, "rra", 4))
		rra(a, config);
	else if (!ft_strncmp(op, "rrb", 4))
		rrb(b, config);
	else if (!ft_strncmp(op, "rrr", 4))
		rrr(a, b, config);
	else
		return (0);
	return (1);
}

int	print_error(const char *debug_info, int debug_mode)
{
	ft_putstr_fd("Error\n", 2);
	if (debug_mode)
		ft_printf("%s\n", debug_info);
	return (0);
}

int	main(int argc, char **argv)
{
	t_config	config;
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		*curr_op;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	ft_bzero(&config, sizeof(config));
	config.size = parse_arguments(argc, argv, &stack_a, 0);
	ft_printf("PARSED SIZE: %d\n", config.size);
	if (!config.size)
		return (free_stack(stack_a), 1);
	curr_op = get_next_line(0);
	while (curr_op)
	{
		if (!do_operation(curr_op, &stack_a, &stack_b, &config))
			return (free(curr_op), free_stack(stack_a),
				free_stack(stack_b), 1);
		free(curr_op);
		curr_op = get_next_line(0);
	}
	if (!stack_b && is_sorted(stack_a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}