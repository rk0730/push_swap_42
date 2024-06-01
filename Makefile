CC = cc
AR = ar rc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src

SRCS = $(SRC_DIR)/ft_main.c \

LIST = list.a
LIST_DIR = $(SRC_DIR)/list

LIST_SRCS = $(LIST_DIR)/ft_error.c \
	$(LIST_DIR)/ft_error2.c \
	$(LIST_DIR)/ft_exit.c \
	$(LIST_DIR)/ft_genlist.c \
	$(LIST_DIR)/ft_list_info.c \
	$(LIST_DIR)/ft_operations.c \
	$(LIST_DIR)/ft_operations2.c \
	$(LIST_DIR)/ft_operations3.c

LIST_OBJS = $(LIST_SRCS:.c=.o)


OBJS = $(SRCS:.c=.o)

NAME = push_swap

LIBFT_DIR = libft
LIBFT = libft.a

FTPRINTF_DIR = ft_printf
FTPRINTF = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIST) $(LIBFT) $(FTPRINTF)
	$(CC) $(CFLAGS) -I. -o $(NAME) $(OBJS) $(LIST) $(LIBFT_DIR)/$(LIBFT) $(FTPRINTF_DIR)/$(FTPRINTF)

$(LIST): $(LIST_OBJS) $(LIBFT) $(FTPRINTF)
	$(AR) $(LIST) $(LIST_OBJS) $(LIBFT_DIR)/$(LIBFT) $(FTPRINTF_DIR)/$(FTPRINTF)

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
