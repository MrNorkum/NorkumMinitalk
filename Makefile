RM = rm -rf
CC = gcc
FLAG = -Wall -Wextra -Werror
CMPL = $(CC) $(FLAG)
C_NAME = client
S_NAME = server
C_NAME_B = client_bonus
S_NAME_B = server_bonus

all: $(C_NAME) $(S_NAME)
$(C_NAME):
	@$(CMPL) client.c ft_printf.c -o $(C_NAME)
$(S_NAME):
	@$(CMPL) server.c ft_printf.c -o $(S_NAME)
bonus: $(C_NAME_B) $(S_NAME_B)
$(C_NAME_B):
	@$(CMPL) client_bonus.c ft_printf.c -o $(C_NAME_B)
$(S_NAME_B):
	@$(CMPL) server_bonus.c ft_printf.c -o $(S_NAME_B)
clean:
	@$(RM) $(C_NAME) $(S_NAME) $(C_NAME_B) $(S_NAME_B)
norm:
	@norminette
run: re
	@./server
brun: bre
	@./server_bonus
fclean: clean
re: clean all
bre: clean bonus
.PHONY: all bonus clean fclean re
