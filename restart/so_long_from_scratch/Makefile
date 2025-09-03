#------Variaveis------#

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = srcs/main.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@echo "🖋️Linkando $(NAME)..."
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
		@echo "🚧 Compilando $<...."
		$(CC) $(CFLAGS) -I includes -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re