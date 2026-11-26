/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 19:52:09 by ishlepch          #+#    #+#             */
/*   Updated: 2026/11/19 20:10:41 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

typedef struct s_stash
{
	char	*str;
	size_t	cap;
	size_t	len;
}	t_stash;

char	*get_next_line(int fd);
char	*stash_join(char *stash, char *buffer, size_t *cap, size_t *len);
char	*copy_till(char *s, int nl);
int		check_line_end(char *str);
size_t	ft_strlen(const char *s);

#endif
