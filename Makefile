CC = cc
AR = ar rc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src

PS_DIR = $(SRCDIR)/mandatory

PS_SRCS = $(PS_DIR)/ft_main.c \
	$(PS_DIR)/ft_sort.c \
	$(PS_DIR)/ft_sort2.c \
	$(PS_DIR)/ft_sort3.c \
	$(PS_DIR)/ft_sort_help.c \
	$(PS_DIR)/ft_utils.c \
	$(PS_DIR)/ft_top_a.c \
	$(PS_DIR)/ft_top_b.c \
	$(PS_DIR)/ft_bottom_a.c \
	$(PS_DIR)/ft_bottom_b.c

PS_OBJS = $(PS_SRCS:.c=.o)

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

BONUS_DIR = $(SRCDIR)/bonus

BONUS_SRCS = $(BONUS_DIR)/ft_main.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

BONUS_NAME = checker

all: $(NAME)

$(NAME): $(PS_OBJS) $(LIST_OBJS) $(LIBFT) $(FTPRINTF)
	$(CC) $(CFLAGS) -I. -o $(NAME) $(PS_OBJS) $(LIST_OBJS) $(LIBFT_DIR)/$(LIBFT) $(FTPRINTF_DIR)/$(FTPRINTF)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIST_OBJS) $(LIBFT) $(FTPRINTF)
	$(CC) $(CFLAGS) -I. -o $(BONUS_NAME) $(BONUS_OBJS) $(LIST_OBJS) $(LIBFT_DIR)/$(LIBFT) $(FTPRINTF_DIR)/$(FTPRINTF)

$(LIBFT):
	make -C $(LIBFT_DIR) all

$(FTPRINTF):
	make -C $(FTPRINTF_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(PS_OBJS) $(LIST_OBJS)
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
