# ------Variaveis------

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ../libft
FT_PRINTF_DIR = ../ft_printf
MLX_DIR = ../minilibx
INC_DIR = includes

SRC = 	srcs/parser/map_main.c \
		srcs/parser/map_setup.c \
		srcs/parser/map_parser.c \
		srcs/parser/map_struct.c \
		srcs/parser/map_fill.c \
		srcs/validation/map_validation.c \
		srcs/validation/validate_borders.c \
		srcs/validation/validate_chars.c \
		srcs/validation/validate_entities.c \
		srcs/validation/find_positions.c \
		srcs/validation/validate_path.c  \
		srcs/graphics/init_graphics.c \
		srcs/graphics/load_textures.c \
		srcs/graphics/render_map.c \
		srcs/graphics/enemy_animation.c \
		srcs/graphics/animate.c \
		srcs/graphics/hud_display.c \
		srcs/gameplay/cleanup.c \
		srcs/gameplay/gameplay.c \
		srcs/gameplay/enemy_movement.c 

OBJ = $(SRC:.c=.o)


all: libs $(NAME)

$(NAME): $(OBJ)
	@echo "🖋️Linkando $(NAME)..."
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -o $(NAME)

%.o: %.c
	@echo "🚧 Compilando $<...."
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)/includes -I$(MLX_DIR)  -c $< -o $@

libs:
	@echo "🥌  Compilando libft"
	$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@echo "🖨️  Compilando ft_printf..."
	$(MAKE) -C $(FT_PRINTF_DIR) --no-print-directory
	@echo "🦜  Compilando MiniLibX..."
	$(MAKE) -C $(MLX_DIR) --no-print-directory
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

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