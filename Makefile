RM = rm -rf
CC = gcc
FLAG = -Wall -Wextra -Werror
CMPL = $(CC) $(FLAG)
C_NAME = client
S_NAME = server
C_SRC = client.c ft_printf.c
S_SRC = server.c ft_printf.c

all: $(C_NAME) $(S_NAME)

$(C_NAME):
	@$(CMPL) $(C_SRC) -o $(C_NAME)

$(S_NAME):
	@$(CMPL) $(S_SRC) -o $(S_NAME)

clean:
	@$(RM) $(C_NAME) $(S_NAME)

fclean: clean

re: fclean all

norm:
	@norminette

run: re
	@./server

.PHONY: all clean fclean re run norm
