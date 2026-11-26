/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 12:33:55 by ishlepch          #+#    #+#             */
/*   Updated: 2026/11/26 22:35:08 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_config	config;
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			i;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	ft_bzero(&config, sizeof(config));
	if (!parse_options(argc, argv, &config, &i))
		return (1);
	config.size = parse_arguments(argc, argv, &stack_a, i);
	if (!config.size)
		return (free_stack(stack_a), 1);
	config.disorder = compute_disorder(stack_a);
	sort(&stack_a, &stack_b, &config);
	print_benchmark(&config, config.disorder);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

void	sort(t_stack **stack_a, t_stack **stack_b, t_config *config)
{
	if (config->disorder == 0.0)
	{
		free_stack(*stack_a);
		exit(0);
	}
	if (config->strategy == SIMPLE)
		insertion_sort(stack_a, stack_b, config);
	else if (config->strategy == MEDIUM)
		chunk_sort(stack_a, stack_b, config);
	else if (config->strategy == COMPLEX)
		radix_sort(stack_a, stack_b, config);
	else
	{
		if (config->disorder < 0.2)
			insertion_sort(stack_a, stack_b, config);
		else if (config->disorder < 0.5)
			chunk_sort(stack_a, stack_b, config);
		else
			radix_sort(stack_a, stack_b, config);
	}
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->value);
		stack = stack->next;
	}
}

int	print_error(const char *debug_info, int debug_mode)
{
	ft_putstr_fd("Error\n", 2);
	if (debug_mode)
		ft_printf("%s\n", debug_info);
	return (0);
}

double	compute_disorder(t_stack *stack)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*current;
	t_stack	*compare;

	mistakes = 0;
	total_pairs = 0;
	current = stack;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			total_pairs++;
			if (current->value > compare->value)
				mistakes++;
			compare = compare->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / total_pairs);
}
