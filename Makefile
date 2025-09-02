# ============================================================================ #
#                                  VARIÁVEIS                                   #
# ============================================================================ #

NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
MLX_FLAGS	= -lmlx -lXext -lX11 -lm

# Diretórios
SRC_DIR		= srcs
OBJ_DIR		= objs
INC_DIR		= includes
LIBFT_DIR	= libft
MLX_DIR		= minilibx-linux

# Arquivos fonte
SRCS		= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/init/init_game.c \
			  $(SRC_DIR)/init/init_mlx.c \
			  $(SRC_DIR)/map/parse_map.c \
			  $(SRC_DIR)/map/validate_map.c \
			  $(SRC_DIR)/map/flood_fill.c \
			  $(SRC_DIR)/graphics/render.c \
			  $(SRC_DIR)/graphics/textures.c \
			  $(SRC_DIR)/game/movement.c \
			  $(SRC_DIR)/game/collectibles.c \
			  $(SRC_DIR)/game/game_state.c \
			  $(SRC_DIR)/utils/errors.c \
			  $(SRC_DIR)/utils/free.c \
			  $(SRC_DIR)/utils/utils.c

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Cores para output
GREEN		= \033[0;32m
RED			= \033[0;31m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
RESET		= \033[0m

# ============================================================================ #
#                                 REGRAS ESPECIAIS                             #
# ============================================================================ #

# Mostra o conteúdo da marge2.txt antes de compilar
show-marge:
	@if [ -f "marge2.txt" ]; then \
		echo "\n$(BLUE)📄 Marge está Krumplin! 💃:$(RESET)"; \
		cat marge2.txt; \
		echo ""; \
	else \
		echo "\n$(RED)❌ marge2.txt não encontrada!$(RESET)"; \
	fi

# ============================================================================ #
#                                 REGRAS PRINCIPAIS                            #
# ============================================================================ #

all: show-marge libft $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)🔗 Linkando objetos...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) compilado com sucesso!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "$(YELLOW)🔨 Compilando $<...$(RESET)"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

libft:
	@echo "$(BLUE)📚 Compilando libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

clean:
	@echo "$(RED)🧹 Limpando objetos...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	@echo "$(RED)🗑️  Removendo executável...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re libft show-marge
