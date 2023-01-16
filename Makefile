SERVER		=	server

NAME_CLIENT	=	client

SRC			=	server.c

CLIENT		=	client.c utils.c

SERVER_B		=	server_bonus

NAME_CLIENT_B	=	client_bonus

SRC_B			=	server_bonus.c

CLIENT_B		=	client_bonus.c utils.c

LIBFT		=	libft/libft.a

PRINTF		=	printf/libftprintf.a

OBJ			=	$(SRC:.c=.o)

OBJ_CLIENT	=	$(CLIENT:.c=.o)

OBJ_B		=	$(SRC_B:.c=.o)

OBJ_CLIENT_B	=	$(CLIENT_B:.c=.o)

CC			=	gcc -g

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

$(SERVER):	$(OBJ) $(OBJ_CLIENT)
			make -C ./libft
			make -C ./printf
			@echo Libreria compilata!
			$(CC) $(CFLAGS) -o $(SERVER) $(OBJ) $(LIBFT) $(PRINTF)
			$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(LIBFT) $(PRINTF)

$(SERVER_B):	$(OBJ_B) $(OBJ_CLIENT_B)
			make -C ./libft
			make -C ./printf
			@echo Libreria compilata!
			$(CC) $(CFLAGS) -o $(SERVER_B) $(OBJ_B) $(LIBFT) $(PRINTF)
			$(CC) $(CFLAGS) -o $(NAME_CLIENT_B) $(OBJ_CLIENT_B) $(LIBFT) $(PRINTF)

bonus: 		$(SERVER_B)

all:		$(SERVER)

re:			fclean all

clean:
			make clean -C libft
			make clean -C printf
			${RM} $(OBJ) $(OBJ_CLIENT) $(OBJ_B) $(OBJ_CLIENT_B)

fclean: 	clean
			make fclean -C libft
			make fclean -C printf
			${RM} $(SERVER) $(NAME_CLIENT) ${OBJ} $(OBJ_CLIENT) $(SERVER_B) $(NAME_CLIENT_B) ${OBJ_B} $(OBJ_CLIENT_B)
			@echo File .o e libreria rimossi!

.PHONY:		all clean fclean re