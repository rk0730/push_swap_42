CC = cc
AR = ar rc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src

SRCS = $(SRCDIR)/ft_main.c \

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = libft.a

FTPRINTF_DIR = ft_printf
FTPRINTF = libftprintf.a

LIST_DIR = $(SRCDIR)/list
LIST = list.a

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FTPRINTF) $(LIST)
	$(CC) $(CFLAGS) -I. -o $(NAME) $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(FTPRINTF_DIR)/$(FTPRINTF) $(LIST_DIR)/$(LIST)

$(LIBFT):
	make -C $(LIBFT_DIR) all

$(FTPRINTF):
	make -C $(FTPRINTF_DIR) all

$(LIST):
	make -C $(LIST_DIR) all

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(FTPRINTF_DIR) clean
	make -C $(LIST_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(FTPRINTF_DIR) fclean
	make -C $(LIST_DIR) fclean

re: fclean all

# sanitize: $(OBJS) $(LIBFT) $(FTPRINTF)
# 	$(CC) $(CFLAGS) -fsanitize=address -g -I. -o $(NAME) $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(FTPRINTF_DIR)/$(FTPRINTF)

.PHONY: all clean fclean re sanitize
