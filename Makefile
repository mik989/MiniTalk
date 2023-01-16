SERVER		=	server

NAME_CLIENT	=	client

SRC			=	server.c

CLIENT		=	client.c utils.c

LIBFT		=	libft/libft.a

PRINTF		=	printf/libftprintf.a

OBJ			=	$(SRC:.c=.o)

OBJ_CLIENT	=	$(CLIENT:.c=.o)

CC			=	gcc -g

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

$(SERVER):	$(OBJ) $(OBJ_CLIENT)
			make -C ./libft
			make -C ./printf
			@echo Libreria compilata!
			$(CC) $(CFLAGS) -o $(SERVER) $(OBJ) $(LIBFT) $(PRINTF)
			$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(LIBFT) $(PRINTF)

all:		$(SERVER)

re:			fclean all

clean:
			make clean -C libft
			make clean -C printf
			${RM} $(OBJ) $(OBJ_CLIENT)

fclean: 	clean
			make fclean -C libft
			make fclean -C printf
			${RM} $(SERVER) $(NAME_CLIENT) ${OBJ} $(OBJ_CLIENT)
			@echo File .o e libreria rimossi!

.PHONY:		all clean fclean re