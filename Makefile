CC = gcc
FLAG = -Wall -Wextra -Werror
CMPL = $(CC) $(FLAG)
NAME = norkum
C_NAME = client
S_NAME = server
RM = rm -rf
C_SRC = client.c
S_SRC = server.c
OBJ = client.o server.o

all: $(C_NAME) $(S_NAME)
a: all

$(C_NAME):
	@$(CMPL) -c $(C_SRC)
	@$(CMPL) $(C_SRC) -o $(C_NAME)

$(S_NAME):
	@$(CMPL) -c $(S_SRC)
	@$(CMPL) $(S_SRC) -o $(S_NAME)

b: bonus
bonus:
	@$(CMPL) -c $(C_SRC)
	@$(CMPL) -c $(S_SRC)
	@$(CMPL) $(S_SRC) -o $(S_NAME)
	@$(CMPL) $(C_SRC) -o $(C_NAME)

c: clean
clean:
	@$(RM) $(OBJ)

f: fclean
fclean: clean
	@$(RM) $(C_NAME) $(S_NAME)

re: fclean all

r:
	@make re
	@make clean

n: norm
norm:
	@norminette

.PHONY: all clean fclean re
