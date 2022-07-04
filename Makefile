### COMPILATION ###

CC	=	gcc

### FILES ###

SRC	=	$(wildcard ./src/*.c)
OBJ =	$(SRC:.c=.o)
OUT	=	$(OBJ:.o=)
NAME	=	malloc_lib

### FLAGS ###

EFLAGS	=	-Wextra -Werror -Wall -Wconversion -Wundef -Wshadow
CFLAGS	=	-c -fPIC
SHARED	=	-shared
LIB	=	-I include/

### COMMANDS ###

RM	=	rm -f
DISP	=	echo -e

### COLORS ###

RESET	=	\033[0m
BOLD	=	\033[1m
GREY	=	\033[30m
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
PURPLE	=	\033[35m
CYAN	=	\033[36m
WHITE	=	\033[37m

### INSTRUCTIONS ###

all: $(NAME)

$(NAME) : $(OBJ)
	@$(DISP) "$(BOLD)$(GREEN)[+]$(PURPLE) $(CC) $(YELLOW) $(EFLAGS) $(SHARED) $(LIB) $(GREEN) $@$(RESET)"
	@$(CC) $(SRC) $(EFLAGS) $(SHARED) $(LIB) -o $(NAME)
	@$(DISP) ""
	@$(DISP) "$(BOLD)$(GREEN)LIBRARY $(NAME) COMPILED !$(RESET)"

clean:
	@for file in $(OBJ) ; do \
		$(DISP) "$(RED)[-] Removing $(BLUE)$${file}$(RESET)"; \
		$(RM) $${file}; \
	done

fclean: clean
	@$(DISP) "$(BOLD)$(RED)[-] Removing $(BLUE)$(NAME)$(RESET)"
	@$(RM) $(NAME)

re: fclean all

%.o: %.c
	@$(DISP) "$(GREEN)[+]$(PURPLE) $(CC) $(YELLOW) $(EFLAGS) $(CFLAGS) $(LIB) $(GREEN) $@ $(RESET)"
	@$(CC) $(EFLAGS) $(CFLAGS) $(LIB) $^ -o $@