CC = cc 

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printfutil.c ft_puthex.c

NAME = libftprintf.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJSB)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re