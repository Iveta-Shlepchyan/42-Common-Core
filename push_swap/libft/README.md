# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    README.md                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/25 19:42:58 by ishlepch          #+#    #+#              #
#    Updated: 2026/06/25 19:43:04 by ishlepch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

*This project has been created as part of the 42 curriculum by ishlepch.*

# Description
This project is a C library containing reimplementations of functions from standard C libraries such as <ctype.h>, <stdlib.h>, <strings.h>, and <string.h>. The goal was to rewrite these functions to better understand how our frequently used functions actually work under the hood.
The library will be used in future 42 curriculum projects.
All code in this repository follows the 42 Norm.

**Functions from <ctype.h> library**
ft_isascii - Test a character to see if it's a 7-bit ASCII character.
ft_isalpha - Test a character to see if it's alphabetic.
ft_isdigit - Test a character to see if it's a decimal digit.
ft_isalnum - Test a character to see if it's alphanumeric.
ft_isprint - Test a character to see if it's any printable character, including a space.
ft_tolower - Convert a character to lowercase.
ft_toupper - Convert a character to uppercase.

**Functions from <stdlib.h> library**
ft_atoi - Convert ASCII string to integer.
ft_calloc - Allocate space for an array and initializes it to 0. This function and malloc return a void pointer, that had no associated data type with it. A void pointer can hold address of any type and can be typecasted to any type.

**Functions from <strings.h> library**
ft_bzero - Set the first part of an object to null bytes (filling it with zeroes).
ft_memset - Set memory to a given value.
ft_memchr - Find the first occurrence of a character in a buffer (locate byte in byte string).
ft_memcmp - Compare the bytes in two buffers.
ft_memmove - Copy bytes from one buffer to another, handling overlapping memory correctly.
ft_memcpy - Copy bytes from one buffer to another.

**Functions from <string.h> library**
ft_strlen - Get the length of a string.
ft_strchr - Find the first occurrence of a character in a string.
ft_strrchr - Find the last occurrence of a character in a string.
ft_strnstr - Locate a substring in a string.
ft_strncmp - Compare two strings, up to a given length.
ft_strdup - Create a duplicate of a string, using malloc.
ft_strlcpy - Size-bounded string copy.
ft_strlcat - Size-bounded string concatenation.

**Non-standard functions**
ft_itoa - Convert integer to ASCII string.
ft_substr - Get a substring from string.
ft_strtrim - Trim beginning and end of string with the specified substring.
ft_strjoin - Concatenate two strings into a new string, using calloc.
ft_split - Split string, with specified character as delimiter, into an array of strings.
ft_strmapi - Create new string from a string modified with a specified function.
ft_striteri - Modify a string with a given function.
ft_putchar_fd - Output a character to given file.
ft_putstr_fd - Output string to given file.
ft_putendl_fd - Output string to given file with newline.
ft_putnbr_fd - Output integer to given file.

**Linked list functions**
ft_lstnew - Create new list.
ft_lstsize - Count elements of a list.
ft_lstlast - Find last element of list.
ft_lstadd_back - Add new element at end of list.
ft_lstadd_front - Add new element at beginning of list.
ft_lstdelone - Delete element from list.
ft_lstclear - Delete sequence of elements of list from a starting point.
ft_lstiter - Apply function to content of all list's elements.
ft_lstmap - Apply function to content of all list's elements into new list.

**Requirements**
The library needs the gcc compiler, with <stdlib.h> and <unistd.h> standard libraries to run.

# Instructions
Compile the library:
make        # Compile the library -> generates libft.a
make clean  # Remove object files
make fclean # Remove object files and library
make re     # Rebuild everything

Using the Library:

To use the library simply include this header:
#include "libft.h"

# Resources
Linux manual pages (man)
Stack Overflow
W3Schools - https://www.w3schools.com/
libftTester - library was tested using https://github.com/Tripouille/libftTester#
AI

**AI Usage**
AI was used as a learning tool during development. Specifically, it was used to clarify concepts and suggest possible improvements to efficiency, particularly during times at school when there were no peers available to ask for help.
