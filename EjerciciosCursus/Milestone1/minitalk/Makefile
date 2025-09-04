SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server client

server: server.o libft
	$(CC) -o $@ $< -Llibft -lft

client: client.o libft
	$(CC) -o $@ $< -Llibft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	
fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re

# CC = cc
# AR = ar rcs
# CFLAGS = -Wall -Wextra -Werror

# MY_SOURCE = client.c server.c

# MY_OBJECTS = $(MY_SOURCE:.c=.o)

# all: client server

# server:
# 	$(CC) -o $@ $< -Libft

# client:
# 	$(CC) -o $@ $< -Libft

# %.o: %.c
# 	$(CC) $(CFLAGS) $?

# $(NAME): $(MY_OBJECTS)
# 	$(AR) $(NAME) $(MY_OBJECTS)
# 	chmod 755 $(NAME)

# libft:
# 	make -C libft
	
# clean:
# 	rm -f $(MY_OBJECTS)
# 	make -C libft clean

# fclean: clean
# 	rm -f client server libft/libft.a

# re: fclean all

# .PHONY: all libft clean fclean re