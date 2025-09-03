# ------Variaveis------

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ../libft
FT_PRINTF_DIR = ../ft_printf
INC_DIR = includes

SRC = srcs/main.c \
		srcs/map_parser.c
OBJ = $(SRC:.c=.o)


all: libs $(NAME)

$(NAME): $(OBJ)
	@echo "🖋️Linkando $(NAME)..."
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME)

%.o: %.c
	@echo "🚧 Compilando $<...."
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -c $< -o $@

libs:
	@echo "🥌Compilando libft"
	$(MAKE) -C $(LIBFT_DIR)
	@echo "🖨️  Compilando ft_printf..."
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

show-marge:
	@if [ -f "marge2.txt" ]; then \
		echo "\n$(BLUE)📄 Marge está Krumplin! 💃:$(RESET)"; \
		cat marge2.txt; \
		echo ""; \
	else \
		echo "\n$(RED)❌ marge2.txt não encontrada!$(RESET)"; \
	fi

.PHONY: all clean fclean re libft