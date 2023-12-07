LIBFT = ./libft
LIBFT_LIBRARY = $(LIBFT)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT)
LDFLAGS = -L $(LIBFT) -lft

EXECUTABLE = a.out
SOURCE = main.c

all: $(EXECUTABLE)

$(LIBFT_LIBRARY):
	$(MAKE) -C $(LIBFT)

$(EXECUTABLE): $(LIBFT_LIBRARY) $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(EXECUTABLE) $(LDFLAGS)
	
%.o : %.c
	$(CC) $(CFLAGS) $< -c $(LDFLAGS)

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(EXECUTABLE)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re
