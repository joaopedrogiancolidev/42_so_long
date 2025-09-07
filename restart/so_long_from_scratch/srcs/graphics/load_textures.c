/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:17:43 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/06 21:39:40 by jgiancol         ###   ########.fr       */
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
	
	ft_printf("🧪 Testing wall texture...\n");
	game->textures.wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &width, &height);
	ft_printf("🧱 Wall result: %p\n", (void *)game->textures.wall);
	
	ft_printf("🧪 Testing floor texture...\n");
	game->textures.floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &width, &height);
	ft_printf("🧹 Floor result: %p\n", (void *)game->textures.floor);

	ft_printf("🧪 Testing exit texture...\n");
	game->textures.exit = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", &width, &height);
	ft_printf("🚫 exit result: %p\n", (void *)game->textures.floor);
	
	ft_printf("🧪 Testing player texture...\n");
	game->textures.player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &width, &height);
	ft_printf("💃 player result: %p\n", (void *)game->textures.floor);

	ft_printf("🧪 Testing collectible texture...\n");
	game->textures.collectible = mlx_xpm_file_to_image(game->mlx, "assets/collect.xpm", &width, &height);
	ft_printf("🦰 collectible result: %p\n", (void *)game->textures.floor);

	ft_printf("🧪 Testing enemies texture...\n");
	game->textures.enemies = mlx_xpm_file_to_image(game->mlx, "assets/enemies.xpm", &width, &height);
	ft_printf("🛀 enemies result: %p\n", (void *)game->textures.floor);

	//load_verification(game);
}
