CC = cc
AR = ar rc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = .
INCDIR = .

SRCS = $(SRCDIR)/ft_error.c \
	$(SRCDIR)/ft_error2.c \
	$(SRCDIR)/ft_exit.c \
	$(SRCDIR)/ft_genlist.c \
	$(SRCDIR)/ft_list_info.c \
	$(SRCDIR)/ft_operations.c \
	$(SRCDIR)/ft_operations2.c \
	$(SRCDIR)/ft_operations3.c

OBJS = $(SRCS:.c=.o)

NAME = list.a

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
