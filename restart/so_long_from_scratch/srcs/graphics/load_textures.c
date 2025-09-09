/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:17:43 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/09 18:25:20 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Nova função: Carrega texturas básicas (wall, floor, exit)
static void	load_basic_textures(t_game *game, int width, int height)
{
	game->textures.wall = mlx_xpm_file_to_image(game->mlx,
			"assets/tile/wall.xpm", &width, &height);
	game->textures.floor = mlx_xpm_file_to_image(game->mlx,
			"assets/tile/floor.xpm", &width, &height);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx,
			"assets/exit/determination_light_1.xpm", &width, &height);
}

// Nova função: Carrega sprites do player
static void	load_player_textures(t_game *game, int width, int height)
{
	game->textures.player[DOWN] = mlx_xpm_file_to_image(game->mlx,
			"assets/player/frisk_front_2.xpm", &width, &height);
	game->textures.player[UP] = mlx_xpm_file_to_image(game->mlx,
			"assets/player/frisk_back.xpm", &width, &height);
	game->textures.player[LEFT] = mlx_xpm_file_to_image(game->mlx,
			"assets/player/frisk_left.xpm", &width, &height);
	game->textures.player[RIGHT] = mlx_xpm_file_to_image(game->mlx,
			"assets/player/frisk_right.xpm", &width, &height);
}

// Nova função: Carrega collectibles
static void	load_collectible_textures(t_game *game, int width, int height)
{
	game->textures.collectible[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/collectibles/collect_1.xpm", &width, &height);
	game->textures.collectible[1] = mlx_xpm_file_to_image(game->mlx,
			"assets/collectibles/collect_2.xpm", &width, &height);
}

// Nova função: Carrega inimigos
static void	load_enemy_textures(t_game *game, int width, int height)
{
	game->textures.enemies[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/enemies/Sans_left.xpm", &width, &height);
	game->textures.enemies[1] = mlx_xpm_file_to_image(game->mlx,
			"assets/enemies/Sans_right.xpm", &width, &height);
}

// Função principal agora com apenas 11 linhas
void	load_textures(t_game *game)
{
	int		width;
	int		height;

	width = TILE_SIZE;
	height = TILE_SIZE;
	load_basic_textures(game, width, height);
	load_player_textures(game, width, height);
	load_collectible_textures(game, width, height);
	load_enemy_textures(game, width, height);
}
