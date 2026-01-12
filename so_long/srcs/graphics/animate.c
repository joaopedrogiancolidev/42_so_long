/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 23:42:44 by jgiancol          #+#    #+#             */
/*   Updated: 2025/11/03 13:09:47 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_animated_entities(t_game *game, int frame)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->grid[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window,
					game->textures.collectible[frame],
					x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map->grid[y][x] == 'M')
				mlx_put_image_to_window(game->mlx, game->window,
					game->textures.enemies[frame],
					x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	render_enemies_with_direction(game);
}

int	animate_game(t_game *game)
{
	static int	animation_frame = 0;

	if (!game || game->game_over)
		return (0);
	game->frame_count++;
	if (game->frame_count % 2 == 0)
	{
		animation_frame = !animation_frame;
		game->needs_rerender = 1;
	}
	move_enemies(game);
	if (game->needs_rerender)
	{
		render_static_map(game);
		render_animated_entities(game, animation_frame);
		render_static_player(game);
		render_full_hud(game);
		game->needs_rerender = 0;
	}
	return (0);
}
