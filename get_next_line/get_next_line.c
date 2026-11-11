/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 20:41:56 by ishlepch          #+#    #+#             */
/*   Updated: 2026/10/20 20:41:57 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



    		// check buffer each char till reach ´/n' 
    		// store everything up to /n (if founded) into array that we return in the end
    		// but how do we know what size of array to make ? end with /n if it also does so
    		// https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/
    		// https://42-cursus.gitbook.io/guide/1-rank-01/get_next_line
    		// to store use stash - either a static string (char array) super big ?
    		// that when we reach new line we rewrite the stash starting from zero with the parts that are left and put NULL or smth when we done or only NULL at the start if no other line part is in the buffer
    		
    		// or linked list - add each char orrr buffer size char array ? last one restart and make the head free and delete previous ones ?
    		
    		/*1.  allocate/resize stash using a helper function (like ft_strjoin) every time read() brings in a new chunk of BUFFER_SIZE.
2. When you find a newline \n, you extract the line.
3. You overwrite or move the stash pointer forward to keep only the leftover data for the next call, freeing the old memory. */ 
#include "get_next_line.h"
#include <stdlib.h> 



size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	stash_join(char *stash, char *buffer)
{
	size_t	len_st;
	size_t	len_buf;
	char	*new_s;
	int	i;

	//if (!stash && !buffer)
	//	return (NULL);
	len_st = ft_strlen(stash);
	len_buf = ft_strlen(buffer);
	
	new_s = malloc(len_st + len_buf + 1);
	//if (!new_s)
		//return (NULL);
		
	i = 0;
	while(stash[i])
	{
		new_s[i] = stash[i];
		i++;
	}
	while(*buffer)
	{
		new_s[i] = *buffer;
		buffer++;
		i++;
	}
	new_s[i] = '\0';
	free(stash);
	stash = new_s;
}


char	*copy_till_nl(char *s, int nl)
{
	size_t	i;
	char	*new_s;
	
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		i++;
	}
	
	new_s = malloc(i + 1 + nl);
	if (!new_s)
		return (NULL);
		
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		new_s[i] = s[i];
		i++;
	}
	if	(nl)
		new_s[i++] = '\n';
	new_s[i] = '\0';
	return (new_s);
}

void	clean_stash(char *s)
{
	size_t	i;
	size_t	j;
	char	*new_s;
	
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		i++;
	}
	i++;
	j = 0;
	while (s[i])
	{
		j++;
		i++;
	}
	
	new_s = malloc(j + 1);
	//if (!new_s)
		//return (NULL);
	if (new_s)
	{	
		i -= j;
		j = 0;
		while(s[i])
		{
			new_s[j] = s[i];
			i++;
			j++;
		}
		new_s[j] = '\0';
		free(s);
		s = new_s;
	}
}



int	check_line_end(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}


char *get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	*stash;
	char		*line;
	
	int		bytes_read;

	if(!stash)
		stash = "";

	while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1) > 0))
	{
		buffer[bytes_read] = '\0';
		stash_join(stash, buffer);
		if (check_line_end(buffer))
		{
			line = copy_till_nl(stash, 1);
			clean_stash(stash);
			return (line);
		}
	}
	line = copy_till_nl(stash, 0);
	return (line);
}
