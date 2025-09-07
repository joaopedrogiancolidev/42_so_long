/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 23:42:44 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/07 00:49:15 by jgiancol         ###   ########.fr       */
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
			if (game->map->grid[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->window,
					game->textures.player[frame], x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map->grid[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window,
					game->textures.collectible[frame], x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map->grid[y][x] == 'M')
				mlx_put_image_to_window(game->mlx, game->window,
					game->textures.enemies[frame], x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

int	animate_game(t_game *game)
{
	static int	last_frame = -1;
	int			current_frame;
	
	if (!game || !game->mlx || !game->window)
		return (0);
	
	game->frame_count++;
	current_frame = (game->frame_count / FRAME_CICLE) % 2;
	
	if (current_frame != last_frame || game->needs_rerender)
	{
		// ✅ Alternativa: Limpa e redesenha TUDO
		mlx_clear_window(game->mlx, game->window);
		render_static_map(game);
		render_animated_entities(game, current_frame);
		
		last_frame = current_frame;
		game->needs_rerender = 0;
	}
	return (0);
}

	// if (current_frame != last_frame)
	// 	ft_printf("🔄 Frame changed: %d -> %d (count: %d)\n", 
	// 		last_frame, current_frame, game->frame_count);