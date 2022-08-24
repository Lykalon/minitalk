NAME_C =		client

NAME_S =		server

HEADER =		minitalk.h

HEADER_BONUS =	minitalk_bonus.h

SRC_C = 		client.c mt_atoi.c print_line.c

SRC_S =			server.c print_line.c

SRC_BONUS_C =	client_bonus.c mt_atoi_bonus.c print_line_bonus.c

SRC_BONUS_S =	server_bonus.c print_line_bonus.c

OBJ_C =			$(patsubst %.c,%.o,$(SRC_C))

OBJ_S =			$(patsubst %.c,%.o,$(SRC_S))

OBJ_BONUS_C =	$(patsubst %.c,%.o,$(SRC_BONUS_C))

OBJ_BONUS_S =	$(patsubst %.c,%.o,$(SRC_BONUS_S))

CFLAGS = 		-Wall -Werror -Wextra -I$(HEADER)

CC = 			cc

RM = 			rm -f

all : 			$(NAME_C) $(NAME_S)

$(NAME_C) : 	$(OBJ_C) $(HEADER)
				$(CC) $(CFLAGS) $(OBJ_C) -o $@

$(NAME_S) : 	$(OBJ_S) $(HEADER)
				$(CC) $(CFLAGS) $(OBJ_S) -o $@

%.o : 			%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

bonus:
				make SRC_C="$(SRC_BONUS_C)" SRC_S="$(SRC_BONUS_S)" HEADER="$(HEADER_BONUS)" all

clean:
				$(RM) $(OBJ_C) $(OBJ_S) $(OBJ_BONUS_C) $(OBJ_BONUS_S) $(D_BONUS_C) $(D_BONUS_S)

fclean: 		clean
				$(RM) $(NAME_C) $(NAME_S)


re: 			fclean all

.PHONY: 		all clean fclean re bonus