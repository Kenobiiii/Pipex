LIB = ar rcs
RM = rm -f

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

NAME = pipex
SRC = 
OBJ = $(SRC:.c=.o)
INCLUDE = 

# Colores
#
GREEN = \033[1;32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	@echo "$(GREEN)Compiling objects...$(RESET)"
	@$(LIB) $(NAME) $(OBJ)
	@echo "$(GREEN)Library created: $(NAME)$(RESET)"

%.o: %.c
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(CC) $(CCFLAGS) -c -o $@ $<
	@echo "$(GREEN)$< compiled!$(RESET)"

clean:
	@echo "$(GREEN)Cleaning...$(RESET)"
	@$(RM) $(OBJ)
	@echo "$(GREEN)Clean complete.$(RESET)"

fclean: clean
	@echo "$(GREEN)Deleting $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)Deleted $(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re