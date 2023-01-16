SERVER		=	server

NAME_CLIENT	=	client

SRC			=	server.c

CLIENT		=	client.c utils.c

LIBFT		=	libft/libft.a

OBJ			=	$(SRC:.c=.o)

OBJ_CLIENT	=	$(CLIENT:.c=.o)

CC			=	gcc -g

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

$(SERVER):	$(OBJ) $(OBJ_CLIENT)
			make -C ./libft
			@echo Libreria compilata!
			$(CC) $(CFLAGS) -o $(SERVER) $(OBJ) $(LIBFT)
			$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(LIBFT)

all:		$(SERVER)

clean:
			make clean -C libft
			${RM} $(OBJ) $(OBJ_CLIENT)

fclean: 	clean
			make fclean -C libft
			${RM} $(SERVER) $(NAME_CLIENT) ${OBJ} $(OBJ_CLIENT)
			@echo File .o e libreria rimossi!

.PHONY:		all clean fclean re