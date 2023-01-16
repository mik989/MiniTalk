# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 17:36:57 by mgirardi          #+#    #+#              #
#    Updated: 2022/10/11 17:37:02 by mgirardi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = -I.
AR = ar
ARF = -rcs
NAME = libft.a

MAN = 	atoi bzero calloc isalnum isalpha isascii isdigit isprint itoa memchr memcmp memmove memcpy memset putchar_fd \
		putendl_fd putnbr_fd putstr_fd split strchr strdup striteri strjoin strlcat strlcpy strlen strmapi strncmp \
		strnstr strrchr strtrim substr tolower toupper

MANFC = $(addprefix ft_,$(addsuffix .c, $(MAN)))
MANO = $(MANFC:.c=.o)

BON = lstnew lstadd_front lstsize lstlast lstadd_back lstdelone lstclear lstiter lstmap
BONFC = $(addprefix ft_,$(addsuffix .c, $(BON)))
BONO = $(BONFC:.c=.o)

all: $(NAME)

$(NAME): $(MANO)
	$(AR) $(ARF) $@ $^

%.o: %.c
	@$(CC) -c $(CFLAGS) $(INC) $< -o $@

clean:
	@rm -f $(MANO) $(BONO)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus:	$(BONO)
	$(AR) $(ARF) $(NAME) $^

.PHONY: bonus all clean fclean re