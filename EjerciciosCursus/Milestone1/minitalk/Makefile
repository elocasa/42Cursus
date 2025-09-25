NAME_SERVER = server
NAME_CLIENT = client

SRCS_SERVER = server.c utils.c
SRCS_CLIENT = client.c utils.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $@ $(OBJS_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $@ $(OBJS_CLIENT)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re

# SOURCES = server.c client.c
# OBJECTS = $(SOURCES:.c=.o)

# CC = cc
# CFLAGS = -Wall -Wextra -Werror

# all: server client

# bonus: server client

# server: server.o libft
# 	$(CC) -o $@ $< -Llibft -lft

# client: client.o libft
# 	$(CC) -o $@ $< -Llibft -lft

# %.o: %.c
# 	$(CC) -c $(CFLAGS) $?

# libft:
# 	make -C libft

# clean:
# 	rm -f $(OBJECTS)
# 	make -C libft clean
	
# fclean: clean
# 	rm -f server client libft/libft.a

# re: fclean all

# .PHONY: all bonus libft clean fclean re
