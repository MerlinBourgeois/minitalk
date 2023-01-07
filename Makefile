SRC = client.c \
	server.c

OBJ = ${SRC:.c=.o}

NAME = client server

CFLAGS = -Wall -Werror -Wextra

REMOVE = rm -f

COMPILE = gcc $(CFLAGS) -o

all:	client server

client:	client.o
	$(COMPILE) client client.o

server:	server.o
	$(COMPILE) server server.o

clean:
	@$(REMOVE) $(OBJ)

fclean:	clean
	@$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re