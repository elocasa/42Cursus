# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::  #
#    Makefile                                           :+:      :+:    :+:   #
#                                                     +:+ +:+         +:+     #
#    By: diego <diego@student.42.fr>                 +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2025/11/17 00:00:00 by helper             #+#    #+#             #
#    Updated: 2025/11/17 00:00:00 by helper            ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
RM = rm -f

SRCS = $(wildcard srcs/*.c) $(wildcard utils/*.c)
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re libft

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(NAME) built"

# Build libft if needed
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Generic rule
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS)
	@echo "objects removed"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(NAME) removed"

re: fclean all
	@echo "rebuild complete"