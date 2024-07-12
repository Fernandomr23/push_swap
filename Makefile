NAME = push_swap

LIBRARY_DIR = ./libft/
LIBRARY_LIBFT = $(LIBRARY_DIR)/libft.a
LIBRARY_PRINTF = $(LIBRARY_DIR)/ft_printf/libftprintf.a

SOURCES = $(wildcard src/*.c src/commands/*.c utils/*.c)
OBJS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBRARY_LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBRARY_LIBFT) $(LIBRARY_PRINTF) -o $(NAME)

$(LIBRARY_LIBFT):
	@$(MAKE) -C $(LIBRARY_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBRARY_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBRARY_DIR) fclean

re: fclean all

.PHONY: all clean fclean re