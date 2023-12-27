NAME = ftprintf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
HEADER = libprintf.h
FILES = ft_putnbrhexa_printf.c \
        ft_putnbrptr_printf.c \
        ft_utilsPrintf.c \
        ft_itoa.c	\
		ft_uitoa.c	\
		ft_printf.c

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(FILES:.c=.o))

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re