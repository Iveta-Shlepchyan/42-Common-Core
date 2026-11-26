/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 19:44:50 by ishlepch          #+#    #+#             */
/*   Updated: 2026/11/26 19:19:52 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	add_token(t_stack **stack, t_stack **last, char *tok, int *size)
{
	int	value;

	if (!parse_number(tok, &value))
		return (print_error("Invalid number", 0));
	if (is_duplicate(*stack, value))
		return (print_error("Duplicate number", 0));
	if (!add_back(stack, last, value))
		return (print_error("Failed to add number", 0));
	(*size)++;
	return (1);
}

static void	free_split(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	parse_arguments(int argc, char **argv, t_stack **stack, int i)
{
	t_stack	*last;
	char	**tok;
	int		size;
	int		j;

	last = NULL;
	size = 0;
	while (i < argc)
	{
		tok = ft_split(argv[i++], ' ');
		if (!tok)
			return (0);
		j = 0;
		while (tok[j])
		{
			if (!add_token(stack, &last, tok[j++], &size))
				return (free_split(tok), 0);
		}
		free_split(tok);
	}
	return (size);
}

// int	parse_arguments(int argc, char **argv, t_stack **stack, int i)
// {
// 	t_stack	*last;
// 	int		value;
// 	int		size;

// 	last = NULL;
// 	size = 0;
// 	while (i < argc)
// 	{
// 		if (!parse_number(argv[i], &value))
// 			return (print_error("Invalid number", 0));
// 		if (is_duplicate(*stack, value))
// 			return (print_error("Duplicate number", 0));
// 		if (!add_back(stack, &last, value))
// 			return (print_error("Failed to add number", 0));
// 		i++;
// 		size++;
// 	}
// 	return (size);
// }


int	parse_number(char *str, int *result)
{
	int		sign;
	long	num;

	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		num = num * 10 + (*str++ - '0');
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			return (0);
	}
	*result = (int)(num * sign);
	return (1);
}


int	is_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

