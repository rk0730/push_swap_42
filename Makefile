CC = cc
AR = ar rc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src
SRCS = $(SRCDIR)/ft_main.c \
	$(SRCDIR)/ft_sort.c \
	$(SRCDIR)/ft_sort2.c \

OBJS = $(SRCS:.c=.o)

LIST_DIR = $(SRCDIR)/list
LIST_SRCS = $(LIST_DIR)/ft_error.c \
	$(LIST_DIR)/ft_error2.c \
	$(LIST_DIR)/ft_exit.c \
	$(LIST_DIR)/ft_genlist.c \
	$(LIST_DIR)/ft_list_info.c \
	$(LIST_DIR)/ft_operations.c \
	$(LIST_DIR)/ft_operations2.c \
	$(LIST_DIR)/ft_operations3.c

LIST_OBJS = $(LIST_SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = libft.a

FTPRINTF_DIR = ft_printf
FTPRINTF = libftprintf.a

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS) $(LIST_OBJS) $(LIBFT) $(FTPRINTF)
	$(CC) $(CFLAGS) -I. -o $(NAME) $(OBJS) $(LIST_OBJS) $(LIBFT_DIR)/$(LIBFT) $(FTPRINTF_DIR)/$(FTPRINTF)

$(LIBFT):
	make -C $(LIBFT_DIR) all

$(FTPRINTF):
	make -C $(FTPRINTF_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJS) $(LIST_OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(FTPRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(FTPRINTF_DIR) fclean

re: fclean all

# sanitize: $(OBJS) $(LIBFT) $(FTPRINTF)
# 	$(CC) $(CFLAGS) -fsanitize=address -g -I. -o $(NAME) $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(FTPRINTF_DIR)/$(FTPRINTF)

.PHONY: all clean fclean re sanitize
