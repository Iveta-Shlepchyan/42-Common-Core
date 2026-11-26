# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/08 17:57:52 by ishlepch          #+#    #+#              #
#    Updated: 2026/11/26 20:03:18 by ishlepch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target executable name
NAME    = push_swap

# Compiler and Flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

# Commands
RM      = rm -f
AR      = ar rcs

# Source files
SRCS    = main.c \
          stack_operations.c \
		  simple_sort.c \
		  med_sort.c \
		  complex_sort.c \
		  arguments_parser.c \
		  options_parser.c \
		  ops_push_swap.c \
		  ops_rotate.c \
		  ops_reverse_rotate.c \
		  sort_small_input.c \
		  utils.c \
		  bench.c

# Object files (automatically maps .c to .o)
OBJS    = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a


# Default rule
all: $(NAME)

bonus: all

# Rules to create the executable
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

# Clean object files and the library
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Re-build everything from scratch
re: fclean all

# Prevent conflicts with files named all, clean, fclean, re
.PHONY: all bonus clean fclean re
