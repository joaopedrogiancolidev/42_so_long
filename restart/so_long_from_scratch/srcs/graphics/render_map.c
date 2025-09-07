/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:13:28 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/06 21:42:45 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_map(t_game *game)
{
	int	y;
	int	x;

	if (!game || !game->map || !game->map->grid)
	{
		ft_printf("❌ ERROR: Invalid game or map in render_map!\n");
		return;
	}
	
	ft_printf("🎨 Rendering map %dx%d...\n", game->map->width, game->map->height);
	
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			// ✅ Verifique cada acesso
			if (y >= game->map->height || x >= game->map->width)
			{
				ft_printf("❌ ERROR: Access out of bounds at (%d,%d)\n", x, y);
				break;
			}
			
			ft_printf("🖼️ Rendering (%d,%d): %c\n", x, y, game->map->grid[y][x]);
			
			mlx_put_image_to_window(game->mlx, game->window,
				game->textures.floor, x * TILE_SIZE, y * TILE_SIZE);
			
			if (game->map->grid[y][x] == '1')
				{
				mlx_put_image_to_window(game->mlx, game->window,
					game->textures.wall, x * TILE_SIZE, y * TILE_SIZE);
				}
			else if (game->map->grid[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->window,
					game->textures.player, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map->grid[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window,
					game->textures.collectible, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map->grid[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window,
					game->textures.exit, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map->grid[y][x] == 'M')
				mlx_put_image_to_window(game->mlx, game->window,
					game->textures.enemies, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	ft_printf("✅ Render completed successfully!\n");
}