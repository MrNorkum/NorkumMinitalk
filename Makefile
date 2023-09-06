RM = rm -rf
CC = gcc
FLAG = -Wall -Wextra -Werror
CMPL = $(CC) $(FLAG)
CLIENT = client
SERVER = server
BCLIENT = client_bonus
BSERVER = server_bonus

all: $(CLIENT) $(SERVER)
$(CLIENT):
	$(CMPL) client.c ft_printf.c -o $(CLIENT)
$(SERVER):
	$(CMPL) server.c ft_printf.c -o $(SERVER)
bonus: $(BCLIENT) $(BSERVER)
$(BCLIENT):
	$(CMPL) client.c ft_printf.c -o $(BCLIENT)
$(BSERVER):
	$(CMPL) server.c ft_printf.c -o $(BSERVER)
clean:
	@$(RM) $(CLIENT) $(SERVER) $(BCLIENT) $(BSERVER)
norm:
	@norminette
run: re
	@./server
brun: clean bonus
	@./server_bonus
fclean: clean
re: clean all
.PHONY: all bonus clean fclean re
