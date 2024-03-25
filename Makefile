NAME = minitalk.a
CC= gcc
CFLAGS= -Wall -Wextra -Werror
RM= rm -rf

PRINTF=ft_printf/libftprintf.a

CLIENT=client
SERVER= server

CLIENT_BONUS=client_bonus
SERVER_BONUS= server_bonus

OBJS= $(SRCS:.c=.o)

SRCS= client.c server.c

BONUS_SRCS = client_bonus.c server_bonus.c

BONUS_OBJS= $(BONUS_SRCS:.c=.o)


all: $(NAME)

$(NAME) : $(SERVER) $(CLIENT) $(OBJS)

$(SERVER): $(OBJS)
	make -C ./ft_printf
	$(CC) $(CFLAGS) server.c $(PRINTF) -o $@

$(CLIENT): $(OBJS)
	$(CC) $(CFLAGS) client.c $(PRINTF) -o $@


bonus: $(SERVER_BONUS) $(CLIENT_BONUS) $(BONUS_OBJS)

$(SERVER_BONUS): $(BONUS_OBJS)
	make -C ./ft_printf
	$(CC) $(CFLAGS) server_bonus.c $(PRINTF) -o $@

$(CLIENT_BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) client_bonus.c $(PRINTF) -o $@


clean:
	make clean -C ./ft_printf
	$(RM)  $(OBJS)  $(BONUS_OBJS)

fclean: clean
	$(RM) $(CLIENT) $(SERVER)  $(CLIENT_BONUS) $(SERVER_BONUS)
	make fclean -C ./ft_printf

re: fclean all bonus

.PHONY : all clean fclean re bonus