NAME = libft.a

CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror

MY_SOURCE = \


MY_OBJECTS = $(MY_SOURCE:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(MY_OBJECTS)
	$(AR) $(NAME) $(MY_SOURCE)
	chmod 755 $(NAME)

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re