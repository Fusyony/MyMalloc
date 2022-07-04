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

### COMMANDS ###

RM	=	rm -f

### INSTRUCTIONS ###

all: $(OBJ)
	$(CC) $(OBJ) $(EFLAGS) $(SHARED) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(EFLAGS) $(CFLAGS) $^ -o $@