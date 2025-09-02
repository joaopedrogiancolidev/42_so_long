NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lXext -lX11 -lm

SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = includes

SRCS = $(wildcard $(SRC_DIR)/*.c) \
        $(wildcard $(SRC_DIR)/init/*.c) \
        $(wildcard $(SRC_DIR)/map/*.c) \
        $(wildcard $(SRC_DIR)/graphics/*.c) \
        $(wildcard $(SRC_DIR)/game/*.c) \
        $(wildcard $(SRC_DIR)/utils/*.c)

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_DIR) -Ilibft -c $< -o $@

libft:
	$(MAKE) -C libft

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

bonus:
	# Implementação dos bônus

.PHONY: all clean fclean re libft bonus
