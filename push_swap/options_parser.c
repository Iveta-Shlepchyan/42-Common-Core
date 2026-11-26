/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 19:20:09 by ishlepch          #+#    #+#             */
/*   Updated: 2026/11/26 20:41:06 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	is_blank(const char *s)
{
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	return (*s == '\0');
}

int	parse_options(int argc, char **argv, t_config *config, int *i)
{
	*i = 1;
	config->bench = 0;
	config->strategy = ADAPTIVE;
	if (is_blank(argv[1]))
		exit(0);

	while (*i < argc && argv[*i][0] == '-' && argv[*i][1] == '-')
	{
		if (ft_strncmp(argv[*i], "--simple", 9) == 0)
			config->strategy = SIMPLE;
		else if (ft_strncmp(argv[*i], "--medium", 9) == 0)
			config->strategy = MEDIUM;
		else if (ft_strncmp(argv[*i], "--complex", 10) == 0)
			config->strategy = COMPLEX;
		else if (ft_strncmp(argv[*i], "--bench", 8) == 0)
			config->bench = 1;
		else if (ft_strncmp(argv[*i], "--adaptive", 11) == 0)
			config->strategy = ADAPTIVE;
		else
			return (print_error("Invalid option", 0));
		(*i)++;
	}
	return (1);
}