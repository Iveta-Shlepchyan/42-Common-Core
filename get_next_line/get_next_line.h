/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 20:42:47 by ishlepch          #+#    #+#             */
/*   Updated: 2026/11/19 19:48:14 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

char	*get_next_line(int fd);

char	*stash_join(char *stash, char *buffer, size_t *cap, size_t *len);
char	*copy_till(char *s, int nl);
int		check_line_end(char *str);
size_t	ft_strlen(const char *s);

#endif