CC = cc
AR = ar rc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_main.c \
	ft_error.c \
	ft_error2.c \
	ft_exit.c \

OBJS = $(SRCS:.c=.o)

NAME = push_swap

LIBFT_DIR = libft
LIBFT = libft.a

FTPRINTF_DIR = ft_printf
FTPRINTF = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FTPRINTF)
	$(CC) $(CFLAGS) -I. -o $(NAME) $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(FTPRINTF_DIR)/$(FTPRINTF)

$(LIBFT):
	make -C $(LIBFT_DIR) all

$(FTPRINTF):
	make -C $(FTPRINTF_DIR) all

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(FTPRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(FTPRINTF_DIR) fclean

re: fclean all

sanitize: $(OBJS) $(LIBFT) $(FTPRINTF)
	$(CC) $(CFLAGS) -fsanitize=address -g -I. -o $(NAME) $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(FTPRINTF_DIR)/$(FTPRINTF)

.PHONY: all clean fclean re sanitize
