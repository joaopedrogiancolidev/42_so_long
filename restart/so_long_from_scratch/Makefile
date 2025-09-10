# ------Variaveis------
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ../libft
FT_PRINTF_DIR = ../ft_printf
MLX_DIR = ../minilibx
INC_DIR = includes

# Arquivos da versão obrigatória
SRC = 	srcs/parser/map_main.c \
		srcs/parser/map_parser.c \
		srcs/parser/map_struct.c \
		srcs/parser/map_fill.c \
		srcs/validation/map_validation.c \
		srcs/validation/validate_borders.c \
		srcs/validation/validate_chars.c \
		srcs/validation/validate_entities.c \
		srcs/validation/find_positions.c \
		srcs/validation/validate_path.c \
		srcs/graphics/init_graphics.c \
		srcs/graphics/load_textures.c \
		srcs/graphics/render_map.c \
		srcs/graphics/animate.c \
		srcs/gameplay/cleanup_textures.c \
		srcs/gameplay/cleanup_game.c \
		srcs/gameplay/cleanup_close.c \
		srcs/gameplay/gameplay_moves.c \
		srcs/gameplay/gameplay_keys.c

# Arquivos bonus adicionais
BONUS_SRC = srcs/bonus/map_main_bonus.c \
			srcs/bonus/map_struct_bonus.c \
			srcs/bonus/validate_entities_bonus.c \
			srcs/bonus/cleanup_game_bonus.c \
			srcs/bonus/enemy_animation_bonus.c \
			srcs/bonus/hud_display_bonus.c \
			srcs/bonus/animate_bonus.c \
			srcs/bonus/load_textures_bonus.c \
			srcs/bonus/cleanup_textures_bonus.c \
			srcs/bonus/gameplay_moves_bonus.c \
			srcs/bonus/enemies_movement_bonus.c \
			srcs/bonus/enemies_init_bonus.c \
			srcs/bonus/enemies_main_bonus.c \
			srcs/bonus/enemies_collision_bonus.c

# Arquivos base + bonus para compilação bonus
SRC_BONUS = $(filter-out srcs/parser/map_main.c srcs/parser/map_struct.c \
					srcs/validation/validate_entities.c srcs/gameplay/cleanup_game.c \
					srcs/graphics/animate.c srcs/graphics/load_textures.c \
					srcs/gameplay/cleanup_textures.c srcs/gameplay/gameplay_moves.c, $(SRC)) \
			$(BONUS_SRC)

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: libs $(NAME)

$(NAME): $(OBJ)
	@echo "🖋️Linkando $(NAME) (versão mandatory)..."
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -o $(NAME)

bonus: libs $(OBJ_BONUS)
	@echo "🖋️Linkando $(NAME) (versão bonus)..."
	$(CC) $(CFLAGS) $(OBJ_BONUS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -o $(NAME)

%.o: %.c
	@echo "🚧 Compilando $<...."
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)/includes -I$(MLX_DIR) -c $< -o $@

libs:
	@echo "🥌  Compilando libft"
	$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@echo "🖨️  Compilando ft_printf..."
	$(MAKE) -C $(FT_PRINTF_DIR) --no-print-directory
	@echo "🦜  Compilando MiniLibX..."
	$(MAKE) -C $(MLX_DIR) --no-print-directory

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
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
		echo "\n📄 Marge está Krumplin! 💃:"; \
		cat marge2.txt; \
		echo ""; \
	else \
		echo "\n❌ marge2.txt não encontrada!"; \
	fi

.PHONY: all bonus clean fclean re libs show-marge