RM = rm -rf
CMPL = gcc -Wall -Wextra -Werror
CLIENT = @$(CMPL) client.c ft_printf.c -o client
SERVER = @$(CMPL) server.c ft_printf.c -o server
CLIENTBONUS = @$(CMPL) client_bonus.c ft_printf.c -o client_bonus
SERVERBONUS = @$(CMPL) server_bonus.c ft_printf.c -o server_bonus

all: client server
client:
	$(CLIENT)
server:
	$(SERVER)
bonus: client_bonus server_bonus
client_bonus:
	$(CLIENTBONUS)
server_bonus:
	$(SERVERBONUS)
clean:
	@$(RM) client server client_bonus server_bonus
norm:
	@norminette *.c *.h
run: 
	@re
	@./server
brun:
	@clean
	@make bonus
	@./server_bonus
fclean: clean
re: clean all
.PHONY: all bonus clean fclean re