/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 23:42:44 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/09 16:17:10 by jgiancol         ###   ########.fr       */
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
					game->textures.collectible[frame], x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map->grid[y][x] == 'M') // ADICIONE ESTA LINHA DE VOLTA
				mlx_put_image_to_window(game->mlx, game->window,
					game->textures.enemies[frame], x * TILE_SIZE, y * TILE_SIZE);		
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

	// 🐢 ANIMAÇÕES BEM LENTAS: A cada 120 frames (0.5 FPS a 60fps)
	if (game->frame_count % 2 == 0)
	{
		animation_frame = !animation_frame;
		game->needs_rerender = 1;
	}

	// 🐌 INIMIGOS: A cada 300 frames (5 segundos a 60fps)
	if (game->frame_count % 5 == 0)
	{
		move_enemies(game);
		game->needs_rerender = 1;
	}

	// 🎯 RENDERIZAÇÃO COMPLETA mas CONTROLADA
	if (game->needs_rerender)
	{
		// ✅ RENDERIZA TUDO, mas apenas quando NECESSÁRIO
		render_static_map(game);
		render_animated_entities(game, animation_frame);
		render_static_player(game);
		render_full_hud(game);
		game->needs_rerender = 0;
		
		// ✅ DEBUG: Mostra que renderizou (opcional)
		static int render_count = 0;
		render_count++;
		if (render_count % 10 == 0)
			ft_printf("🔄 Renderizado %d vezes\n", render_count);
	}

	return (0);
}
	// if (current_frame != last_frame)
	// 	ft_printf("🔄 Frame changed: %d -> %d (count: %d)\n", 
	// 		last_frame, current_frame, game->frame_count);