/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:13:28 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/09 14:08:57 by jgiancol         ###   ########.fr       */
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

void	render_static_player(t_game *game)
{
	int x = game->map->player_pos.x * TILE_SIZE;
	int y = game->map->player_pos.y * TILE_SIZE;

	printf("DEBUG: Renderizando player - Direction: %d\n", game->player_direction);
    printf("DEBUG: Player position: (%d, %d)\n", game->map->player_pos.x, game->map->player_pos.y);
    printf("DEBUG: Pixel position: (%d, %d)\n", x, y);
    printf("DEBUG: MLX pointer: %p\n", game->mlx);
    printf("DEBUG: Window pointer: %p\n", game->window);
    printf("DEBUG: Texture pointer: %p\n", game->textures.player[game->player_direction]);
    
    // Verifica se todos os ponteiros são válidos antes de chamar mlx_put_image_to_window
    if (!game->mlx || !game->window || !game->textures.player[game->player_direction])
    {
        printf("ERRO: Ponteiro NULL detectado!\n");
        return;
	}	
	// Renderiza o player com a direção atual
	mlx_put_image_to_window(game->mlx, game->window,
		game->textures.player[game->player_direction], x, y);
}

// Função auxiliar para renderizar tudo de uma vez (opcional)
void	render_complete_map(t_game *game, int frame)
{
	render_static_map(game);
	render_animated_entities(game, frame);
}
