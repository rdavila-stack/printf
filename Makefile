SRCS = ft_printf.c conversions_3.c conversions_1.c conversions_2.c


OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
