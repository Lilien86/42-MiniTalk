LIBFT = ./libft
LIBFT_LIBRARY = $(LIBFT)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT)
LDFLAGS = -L$(LIBFT) -lft

EXECUTABLE = a.out
SOURCE = main.c

all: $(LIBFT_LIBRARY) $(EXECUTABLE)

$(LIBFT_LIBRARY):
	$(MAKE) -C $(LIBFT)

$(EXECUTABLE): $(SOURCE)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCE) -o $(EXECUTABLE)

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(EXECUTABLE)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re
