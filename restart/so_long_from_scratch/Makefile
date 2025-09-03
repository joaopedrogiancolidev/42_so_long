# ------Variaveis------

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ../libft
INC_DIR = includes

SRC = srcs/main.c \
		srcs/map_parser.c
OBJ = $(SRC:.c=.o)

# REGRA CORRIGIDA: all depende de libft primeiro!
all: libft $(NAME)

$(NAME): $(OBJ)
	@echo "🖋️Linkando $(NAME)..."
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	@echo "🚧 Compilando $<...."
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -c $< -o $@

libft:
	@echo "🥌Compilando libft"
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft