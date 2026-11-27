/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <ishlepch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 20:06:13 by ishlepch          #+#    #+#             */
/*   Updated: 2026/11/27 20:12:38 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"
# include "libft/includes/libft.h"

int		do_operation(char *op, t_stack **a, t_stack **b,
			t_config *config);
int		print_error(const char *debug_info, int debug_mode);

#endif