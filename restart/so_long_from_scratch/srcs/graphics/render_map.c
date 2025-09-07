/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:13:28 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/06 23:28:17 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	render_tile(t_game *game, int x, int y, char tile)
{
	void	*img;

	img = NULL;
	if (tile == '1')
		img = game->textures.wall;
	else if (tile == 'P')
		img = game->textures.player;
	else if (tile == 'C')
		img = game->textures.collectible;
	else if (tile == 'E')
		img = game->textures.exit;
	else if (tile == 'M')
		img = game->textures.enemies;
	if (img)
		mlx_put_image_to_window(game->mlx, game->window, img,
			x * TILE_SIZE, y * TILE_SIZE);
}

static void	render_row(t_game *game, int y)
{
	int		x;
	char	tile;

	x = -1;
	while (++x < game->map->width)
	{
		if (y >= game->map->height || x >= game->map->width)
		{
			ft_printf("❌ ERROR: Access out of bounds at (%d,%d)\n", x, y);
			break ;
		}
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures.floor, x * TILE_SIZE, y * TILE_SIZE);
		tile = game->map->grid[y][x];
		render_tile(game, x, y, tile);
	}
}

void	render_map(t_game *game)
{
	int	y;

	if (!game || !game->map || !game->map->grid)
	{
		ft_printf("❌ ERROR: Invalid game or map in render_map!\n");
		return ;
	}
	ft_printf("🎨 Rendering map %dx%d...\n", game->map->width, game->map->height);
	y = -1;
	while (++y < game->map->height)
		render_row(game, y);
	ft_printf("✅ Render completed successfully!\n");
}
