/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:17:43 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/09 14:13:10 by jgiancol         ###   ########.fr       */
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
			"assets/exit/determination_broke.xpm", &width, &height);
	ft_printf("🚫 exit result: %p\n", (void *)game->textures.floor);
	game->textures.player[DOWN] = mlx_xpm_file_to_image(game->mlx,
		"assets/player/frisk_front_2.xpm", &width, &height);
	ft_printf("🔍 Player DOWN result: %p\n", (void *)game->textures.player[DOWN]);
	game->textures.player[UP] = mlx_xpm_file_to_image(game->mlx,
		"assets/player/frisk_back.xpm", &width, &height);
	ft_printf("🔍 Player UP result: %p\n", (void *)game->textures.player[UP]);
	game->textures.player[LEFT] = mlx_xpm_file_to_image(game->mlx,
		"assets/player/frisk_left.xpm", &width, &height);
	ft_printf("🔍 Player LEFT result: %p\n", (void *)game->textures.player[LEFT]);
	game->textures.player[RIGHT] = mlx_xpm_file_to_image(game->mlx,
		"assets/player/frisk_right.xpm", &width, &height);
ft_printf("🔍 Player RIGHT result: %p\n", (void *)game->textures.player[RIGHT]);	
	ft_printf("💃 player result: %p\n", (void *)game->textures.floor);
	game->textures.collectible[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/collectibles/collect_1.xpm", &width, &height);
	game->textures.collectible[1] = mlx_xpm_file_to_image(game->mlx,
		"assets/collectibles/collect_2.xpm", &width, &height);
	ft_printf("🦰 collectible result: %p\n", (void *)game->textures.floor);
	game->textures.enemies[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/enemies/Sans_left.xpm", &width, &height);
	game->textures.enemies[1] = mlx_xpm_file_to_image(game->mlx,
		"assets/enemies/Sans_right.xpm", &width, &height);	
	ft_printf("🛀 enemies result: %p\n", (void *)game->textures.floor);
	//load_verification(game);
}
