# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ishlepch <ishlepch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/08 17:57:52 by ishlepch          #+#    #+#              #
#    Updated: 2026/11/27 20:53:10 by ishlepch         ###   ########.fr        #
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

# Shared source files
SHARED_SRCS = stack_operations.c \
              arguments_parser.c \
              ops_push_swap.c \
              ops_rotate.c \
              ops_reverse_rotate.c \
              utils.c \
			  simple_sort.c \
			  med_sort.c \
			  complex_sort.c \
			  options_parser.c \
			  sort_small_input.c \
			  bench.c 

# Mandatory source files
SRCS = main.c \
       $(SHARED_SRCS)

# Bonus source files
BONUS_SRCS = checker_bonus.c \
             $(SHARED_SRCS)

# Object files
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Default rule
all: $(NAME)

# Bonus rule
bonus: $(LIBFT) $(BONUS_SRCS)
	$(CC) $(CFLAGS) $(BONUS_SRCS) $(LIBFT) -o checker

# Mandatory executable
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
