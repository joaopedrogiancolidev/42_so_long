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
GNL_DIR 	= get_next_line

# Arquivos fonte
SRCS		= srcs/main.c \
			  srcs/init/init_game.c \
			  srcs/init/init_mlx.c \
			  srcs/map/parse_map.c \
			  srcs/map/validate_map.c \
			  srcs/map/flood_fill.c \
			  srcs/graphics/render.c \
			  srcs/graphics/textures.c \
			  srcs/game/movement.c \
			  srcs/game/collectibles.c \
			  srcs/game/game_state.c \
			  srcs/utils/errors.c \
			  srcs/utils/free.c \
			  srcs/utils/utils.c \
			  get_next_line/get_next_line.c \
			  get_next_line/get_next_line_utils.c

# OBJETOS CORRETO:
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

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

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@echo "$(YELLOW)🔨 Compilando $<...$(RESET)"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(GNL_DIR) -c $< -o $@

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
