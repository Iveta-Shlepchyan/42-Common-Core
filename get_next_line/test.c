/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 17:44:08 by ishlepch          #+#    #+#             */
/*   Updated: 2026/11/11 17:44:20 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <fcntl.h>   // For open() and O_RDONLY
#include <unistd.h>  // For close()
#include <stdio.h>   // For printf()
#include <stdlib.h>  // For free()
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    // 1. Open the file in read-only mode to get the fd
    fd = open("test.txt", O_RDONLY);
    
    // 2. Check if opening the file failed
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    // 3. Pass the fd to get_next_line until EOF (returns NULL)
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // Free the allocated line
    }

    // 4. Close the file descriptor
    close(fd);
    return (0);
}

