/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:22:46 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/07 20:39:34 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../libft/libft.h"
# include "../../ft_printf/includes/ft_printf.h"
# include "../../minilibx/mlx.h" 
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

// Constantes do jogo
# define TILE_SIZE 64
# define FRAME_CICLE 30
# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363

// Estruturas
typedef struct s_position {
    int x;
    int y;
} t_position;

typedef struct s_enemy {
    t_position pos;
    int direction;      // 0=direita, 1=esquerda, 2=baixo, 3=cima
    int movement_type;  // 0=horizontal, 1=vertical
} t_enemy;

typedef struct s_textures {
    void *wall;
    void *floor;
    void *player[2];
    void *collectible[2];
    void *exit;
    void *enemies[2];
} t_textures;

typedef struct s_map {
    char **grid;
    int width;
    int height;
    int collectibles;
    int exits;
    int players;
    int enemies;
    t_position player_pos;
    t_position exit_pos;
    t_position *enemy_pos;      // Manter para compatibilidade
    t_enemy *enemies_data;      // 🆕 Novos dados dos inimigos
} t_map;

typedef struct s_game {
    void *mlx;
    void *window;
    t_map *map;
    t_textures textures;
    int moves;
    int collected;
    int game_over;
    int frame_count;
    int needs_rerender;
} t_game;

// ===== PARSING E VALIDAÇÃO =====
t_map parse_map(char *filename);
void validate_map(t_map *map);
void print_map_info(t_map *map);

// Funções de parsing
int get_map_height_width(char *filename, t_map *map);
void fill_map_grid(char *filename, t_map *map);
void process_line(char *line, t_map *map);
void process_grid_line(char *line, t_map *map, int i, size_t line_len);

// Funções de validação
void validate_characters(t_map *map);
void validate_entities(t_map *map);
void validate_borders(t_map *map);
void validate_path(t_map *map);
void find_positions(t_map *map);

// ===== ESTRUTURAS E UTILIDADES =====
t_map init_map_struct(void);
void free_map(t_map *map);
void throw_error(char *message);

// ===== GRÁFICOS =====
int init_graphics(t_game *game, t_map *map);
void load_textures(t_game *game);
void render_static_map(t_game *game);
void render_animated_entities(t_game *game, int frame);
void render_complete_map(t_game *game, int frame);
int animate_game(t_game *game);

// ===== GAMEPLAY - A IMPLEMENTAR =====
int key_press(int keycode, t_game *game);
void move_player(t_game *game, int new_x, int new_y);
int is_valid_move(t_game *game, int x, int y);
void collect_item(t_game *game, int x, int y);
void check_win_condition(t_game *game);
void display_move_count(t_game *game);

// ===== SISTEMA DE INIMIGOS =====
void init_enemies(t_game *game);
void move_enemies(t_game *game);
int can_enemy_move(t_game *game, int x, int y);
void move_single_enemy(t_game *game, int enemy_index);
void check_player_collision(t_game *game);

// ===== SISTEMA =====
int close_game(t_game *game);
void cleanup_textures(t_game *game);
void cleanup_game(t_game *game);

#endif
