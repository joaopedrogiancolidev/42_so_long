/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:13:28 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/07 00:02:45 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"


void	render_static_map(t_game *game)
{
	int	y;
	int	x;

	if (!game || !game->mlx || !game->window || !game->map)
		return ;
	
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			// Renderiza o chão em todas as posições
			mlx_put_image_to_window(game->mlx, game->window,
				game->textures.floor, x * TILE_SIZE, y * TILE_SIZE);
			
			// Renderiza elementos estáticos
			if (game->map->grid[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->window,
					game->textures.wall, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map->grid[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window,
					game->textures.exit, x * TILE_SIZE, y * TILE_SIZE);
			
			x++;
		}
		y++;
	}
}

// Função auxiliar para renderizar tudo de uma vez (opcional)
void	render_complete_map(t_game *game, int frame)
{
	render_static_map(game);
	render_animated_entities(game, frame);
}
