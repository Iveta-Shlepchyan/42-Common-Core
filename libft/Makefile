# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/25 19:45:33 by ishlepch          #+#    #+#              #
#    Updated: 2026/06/25 19:45:34 by ishlepch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target library name
NAME    = libft.a

# Compiler and Flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

# Commands
RM      = rm -f
AR      = ar rcs

# Source files
SRCS    = ft_isascii.c \
          ft_strlen.c \
          ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_strlcpy.c \
	  ft_strlcat.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strncmp.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strnstr.c \
	  ft_atoi.c \
	  ft_calloc.c \
	  ft_strdup.c \
	  ft_substr.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_split.c \
	  ft_itoa.c \
	  ft_strmapi.c \
	  ft_striteri.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_lstnew.c \
	  ft_lstadd_front.c \
	  ft_lstsize.c \
	  ft_lstlast.c \
	  ft_lstadd_back.c \
	  ft_lstdelone.c \
	  ft_lstclear.c \
	  ft_lstiter.c \
	  ft_lstmap.c

# Object files (automatically maps .c to .o)
OBJS    = $(SRCS:.c=.o)

# Default rule
all: $(NAME)

# Rules to create the library
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	$(RM) $(OBJS)

# Clean object files and the library
fclean: clean
	$(RM) $(NAME)

# Re-build everything from scratch
re: fclean all

# Prevent conflicts with files named all, clean, fclean, re
.PHONY: all clean fclean re

