/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 12:33:46 by ishlepch          #+#    #+#             */
/*   Updated: 2026/11/26 22:14:17 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
# include <limits.h>

typedef enum e_operation
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OP_COUNT
}	t_operation;

typedef struct s_config
{
	int		strategy;
	int		bench;
	double	disorder;
	int		ops[OP_COUNT];
	int		size;
}	t_config;

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

// Input parsing functions
int		parse_options(int argc, char **argv, t_config *config, int *i);
int		parse_arguments(int argc, char **argv, t_stack **stack_a, int i);
int		parse_number(char *str, int *result);
int		is_duplicate(t_stack *stack, int value);


// Stack basic operations
int		add_back(t_stack **stack, t_stack **last, int value);
int		push(t_stack **src, t_stack **dst);
int		swap(t_stack **stack);
int		rotate(t_stack **stack);
int		reverse_rotate(t_stack **stack);
void	free_stack(t_stack *stack);
int		is_sorted(t_stack *stack);
int		get_stack_size(t_stack *s);

// Stack operations
void	sa(t_stack **a, t_config *config);
void	sb(t_stack **b, t_config *config);
void	ss(t_stack **a, t_stack **b, t_config *config);
void	pa(t_stack **a, t_stack **b, t_config *config);
void	pb(t_stack **a, t_stack **b, t_config *config);	
void	ra(t_stack **a, t_config *config);
void	rb(t_stack **b, t_config *config);
void	rr(t_stack **a, t_stack **b, t_config *config);
void	rra(t_stack **a, t_config *config);
void	rrb(t_stack **b, t_config *config);
void	rrr(t_stack **a, t_stack **b, t_config *config);


// Sorting functions
double	compute_disorder(t_stack *stack);
void	assign_indexes(t_stack *a);
void	sort(t_stack **stack_a, t_stack **stack_b, t_config *config);
void	insertion_sort(t_stack **a, t_stack **b, t_config *config);
void	chunk_sort(t_stack **a, t_stack **b, t_config *config);
void	radix_sort(t_stack **a, t_stack **b, t_config *config);
void	sort_small_input(t_stack **a, t_stack **b, t_config *config);

// Utility functions
void	print_stack(t_stack *stack);
int		print_error(const char *debug_info, int debug_mode);
void	print_benchmark(t_config *config, double disorder);
int		get_total_operations(t_config *config);	

#endif