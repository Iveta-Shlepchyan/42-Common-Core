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

#include "get_next_line.h¨

char *get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static int	total_bytes_read;
	int		bytes_read;

    	while ((bytesRead = read(fd, buffer, sizeof(buffer) - 1) > 0)
    	{
    		total_bytes_read += bytes_read;
    		// check buffer each char till reach ´/n' 
    		// store everything up to /n (if founded) into array that we retur in the end
    		// but how do we know what size of array to make ? end with /n if it also does so
    		// https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/
    		// https://42-cursus.gitbook.io/guide/1-rank-01/get_next_line
    		// to store use stash - either a static string (char array) super big ?
    		// that when we reach new line we rewrite the stash starting from zero with the parts that are left and put NULL or smth when we done or only NULL at the start if no other line part is in the buffer
    		
    		// or linked list - add each char orrr buffer size char array ? last one restart and make the head free and delete previous ones ?
    		
    		/*1.  allocate/resize stash using a helper function (like ft_strjoin) every time read() brings in a new chunk of BUFFER_SIZE.
2. When you find a newline \n, you extract the line.
3. You overwrite or move the stash pointer forward to keep only the leftover data for the next call, freeing the old memory. */ 
    	}
	return (NULL);
}
