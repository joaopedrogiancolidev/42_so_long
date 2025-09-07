/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:17:43 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/07 15:51:26 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// static void	load_verification(t_game *game)
// {
// 	if (!game->textures.wall)
// 		throw_error("Failed to load WALL texture");
// 	if (!game->textures.floor)
// 		throw_error("Failed to load FLOOR texture");
// 	if (!game->textures.player)
// 		throw_error("Failed to load PLAYER texture");
// 	if (!game->textures.collectible)
// 		throw_error("Failed to load COLLECTIBLE texture");
// 	if (!game->textures.enemies)
// 		throw_error("Failed to load ENEMIES texture");
// 	if (!game->textures.exit)
// 		throw_error("Failed to load EXIT texture");
// }

void	load_textures(t_game *game)
{
	int		width;
	int		height;

	width = TILE_SIZE;
	height = TILE_SIZE;
	game->textures.wall = mlx_xpm_file_to_image(game->mlx,
			"assets/tile/wall.xpm", &width, &height);
	ft_printf("🧱 Wall result: %p\n", (void *)game->textures.wall);
	game->textures.floor = mlx_xpm_file_to_image(game->mlx,
			"assets/tile/floor.xpm", &width, &height);
	ft_printf("🧹 Floor result: %p\n", (void *)game->textures.floor);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx,
			"assets/exit/exit_1.xpm", &width, &height);
	ft_printf("🚫 exit result: %p\n", (void *)game->textures.floor);
	game->textures.player[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/player/player_front_1.xpm", &width, &height);
	game->textures.player[1] = mlx_xpm_file_to_image(game->mlx,
		"assets/player/player_front_2.xpm", &width, &height);		
	ft_printf("💃 player result: %p\n", (void *)game->textures.floor);
	game->textures.collectible[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/collectibles/collect_1.xpm", &width, &height);
	game->textures.collectible[1] = mlx_xpm_file_to_image(game->mlx,
		"assets/collectibles/collect_2.xpm", &width, &height);
	ft_printf("🦰 collectible result: %p\n", (void *)game->textures.floor);
	game->textures.enemies[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/enemies/enemies_front_1.xpm", &width, &height);
	game->textures.enemies[1] = mlx_xpm_file_to_image(game->mlx,
		"assets/enemies/enemies_front_2.xpm", &width, &height);	
	ft_printf("🛀 enemies result: %p\n", (void *)game->textures.floor);
	//load_verification(game);
}
