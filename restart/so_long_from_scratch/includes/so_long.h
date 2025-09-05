/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:22:46 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/05 18:40:33 by jgiancol         ###   ########.fr       */
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

//Parse map structures
typedef struct s_position
{
	int		x;
	int		y;
}	t_position;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	int			collectibles;
	int			exits;
	int			players;
	int			enemies;
	t_position	player_pos;
	t_position	exit_pos;
	t_position	*enemy_pos;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_map	*map;
}	t_game;

//map parser
t_map	parse_map(char *filename);
void	print_map_info(t_map *map);
void	throw_error(char *message);
t_map	init_map_struct(void);
int		get_map_height_width(char *filename, t_map *map);
void	fill_map_grid(char *filename, t_map *map);
void	process_line(char *line, t_map *map);
void	process_grid_line(char *line, t_map *map, int i, size_t line_len);
void	free_map(t_map *map);

//validation
void	validate_map(t_map *map);
void	validate_characters(t_map *map);
void	validate_entities(t_map *map);
void	validate_borders(t_map *map);
void	find_positions(t_map *map);
void	validate_path(t_map *map);

//graphics
int		init_graphics(t_game *game, t_map *map);

#endif