/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 00:57:42 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/08 00:57:45 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Atualiza a direção do player baseado no movimento
void	update_player_direction(t_game *game, int new_x, int new_y)
{
	int old_x = game->map->player_pos.x;
	int old_y = game->map->player_pos.y;
	
	// Determina a direção baseado no movimento
	if (new_x > old_x) // Moveu para direita
		game->player_direction = 0;
	else if (new_x < old_x) // Moveu para esquerda
		game->player_direction = 1;
	else if (new_y < old_y) // Moveu para cima
		game->player_direction = 2;
	else if (new_y > old_y) // Moveu para baixo
		game->player_direction = 3;
}

// Retorna o sprite correto do player baseado na direção e frame de animação
void	*get_player_sprite(t_game *game, int animation_frame)
{
	// Array de sprites: [direção][frame]
	// 0=direita, 1=esquerda, 2=cima, 3=baixo
	return (game->textures.player[game->player_direction][animation_frame]);
}

// Renderiza o player com animação direcional
void	render_player_with_direction(t_game *game, int animation_frame)
{
	int x = game->map->player_pos.x * TILE_SIZE;
	int y = game->map->player_pos.y * TILE_SIZE;
	void *sprite;
	
	sprite = get_player_sprite(game, animation_frame);
	mlx_put_image_to_window(game->mlx, game->window, sprite, x, y);
}
