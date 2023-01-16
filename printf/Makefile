CC = gcc

NAME = libftprintf.a

SRC =  ft_printf.c		\
	   printf_putchar_fd.c	\
	   printf_putstr_fd.c	\
	   printf_putnbr_fd.c	\
	   printf_putnbr_base.c \
	   printf_function.c	

OBJ_S = $(SRC:.c=.o)

CFLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ_S)
	ar -rcs $@ $^

%.o:%.c
	@$(CC) -c $(CFLAG) -I. $< -o $@

clean: 
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re