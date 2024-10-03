NAME	=	minitalk

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

OBJS = $(FILE:.c=.o)
FT_PRINTF =	ft_printf
CLIENT	=	client
SERVER	=	server

VERMELHO	=	\033[91;1m
VERDE	=	\033[92;1m
YELLOW	=	\033[93;1m
BLUE	=	\033[94;1m
PINK	=	\033[95;1m
CLEAR	=	\033[0m

all:		$(NAME)

$(SERVER):	$(SERVER).c minitalk.h
		@echo "----------------------------------------------------------"
		@echo "| \t \t $(BLUE)Bem vindo ao cliente/servidor$(CLEAR) \t \t |"
		@echo "----------------------------------------------------------"
		
		@echo "\n$(PINK)Compilando servidor.$(CLEAR)"
			@$(CC) $(CFLAGS) -o $(SERVER) $(SERVER).c $(FT_PRINTF).c
			@echo "$(VERDE)[verificado]$(CLEAR)"

$(CLIENT):	$(CLIENT).c minitalk.h
			@echo "$(PINK)Compilando Cliente.$(CLEAR)\n$(VERDE)[verificado]$(CLEAR)"
			@$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT).c $(FT_PRINTF).c
			@echo "$(VERDE)Sucesso!$(CLEAR)\n$(YELLOW)Finalizado$(CLEAR)\n"

$(NAME):	$(SERVER) $(CLIENT) $(OBJS)

clean:
			@echo "$(BLUE)Limpando a tela$(CLEAR)\n$(VERMELHO)Removendo todos os arquivos compilados.$(CLEAR)"
			@$(RM) $(CLIENT) $(SERVER) $(FT_PRINTF)
			@echo "$(VERDE)Sucesso!$(CLEAR)\n$(YELLOW)Finalizado$(CLEAR)\n"

fclean:		clean

re:			fclean all

.PHONY: 	all clean fclean re
