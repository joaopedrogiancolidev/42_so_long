/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:07:10 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/02 17:27:17 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../minilibx-linux-master/minilibx-linux-master/mlx.h"

typedef struct s_position {
    int x;
    int y;
} t_position;

typedef struct s_map {
    char **grid;
    int width;
    int height;
    int collectibles;
    int exits;
    int players;
    t_position player_pos;
    t_position exit_pos;
} t_map;

typedef struct s_game {
    void *mlx;
    void *window;
    t_map map;
    int moves;
    int collected;
    int game_over;
} t_game;

// Funções principais
t_game	init_game(char *map_file);
void	start_game(t_game *game);

// Map functions
t_map	parse_map(char *filename);
int		validate_map(t_map *map);

void	flood_fill(t_map *map, int x, int y, int *collectibles, int *exit);


// Error handling
void	throw_error(char *message);
void	clean_exit(t_game *game, int exit_code);

#endif