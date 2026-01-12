# ------Variaveis------
NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ../ft_lib
FT_PRINTF_DIR = ../printf
MLX_DIR = ../minilibx
INC_DIR = includes

# Arquivos comuns
SRC_COMMON = srcs/parser/map_main.c \
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
		srcs/graphics/enemy_animation.c \
		srcs/graphics/animate.c \
		srcs/gameplay/cleanup_textures.c \
		srcs/gameplay/cleanup_game.c \
		srcs/gameplay/cleanup_close.c \
		srcs/gameplay/gameplay_moves.c \
		srcs/gameplay/gameplay_keys.c \
		srcs/gameplay/enemies_movement.c \
		srcs/gameplay/enemies_init.c \
		srcs/gameplay/enemies_main.c \
		srcs/gameplay/enemies_collision.c

# Arquivos específicos
SRC_MANDATORY = $(SRC_COMMON) srcs/graphics/hud_display.c
SRC_BONUS = $(SRC_COMMON) srcs/graphics/hud_display_bonus.c

# Objetos específicos para evitar conflitos
OBJ_MANDATORY_DIR = obj/mandatory
OBJ_BONUS_DIR = obj/bonus

OBJ_MANDATORY = $(patsubst srcs/%.c,$(OBJ_MANDATORY_DIR)/%.o,$(SRC_MANDATORY))
OBJ_BONUS = $(patsubst srcs/%.c,$(OBJ_BONUS_DIR)/%.o,$(SRC_BONUS))

# Regras principais
all: libs $(NAME)

bonus: libs $(NAME_BONUS)

$(NAME): $(OBJ_MANDATORY)
	@echo "Linkando $(NAME)..."
	$(CC) $(CFLAGS) $(OBJ_MANDATORY) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	@echo "Linkando $(NAME_BONUS) com bonus..."
	$(CC) $(CFLAGS) $(OBJ_BONUS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -o $(NAME_BONUS)

# Compilação objetos mandatory
$(OBJ_MANDATORY_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@echo "Compilando $< (mandatory)..."
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)/includes -I$(MLX_DIR) -c $< -o $@

# Compilação objetos bonus
$(OBJ_BONUS_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@echo "Compilando $< (bonus)..."
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)/includes -I$(MLX_DIR) -c $< -o $@

libs:
	@echo "Compilando ft_lib"
	$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@echo "Compilando ft_printf..."
	$(MAKE) -C $(FT_PRINTF_DIR) --no-print-directory
	@echo "Compilando MiniLibX..."
	$(MAKE) -C $(MLX_DIR) --no-print-directory

clean:
	rm -rf $(OBJ_MANDATORY_DIR) $(OBJ_BONUS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	rm -rf obj/
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus libs
