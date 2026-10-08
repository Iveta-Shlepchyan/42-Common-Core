# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/08 17:57:52 by ishlepch          #+#    #+#              #
#    Updated: 2026/10/08 17:57:56 by ishlepch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target library name
NAME    = libftprintf.a

# Compiler and Flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

# Commands
RM      = rm -f
AR      = ar rcs

# Source files
SRCS    = ft_printf.c

# Object files (automatically maps .c to .o)
OBJS    = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a



# Default rule
all: $(NAME)

# Rules to create the library
$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)
	
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
.PHONY: all clean fclean re
