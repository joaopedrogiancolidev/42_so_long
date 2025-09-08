/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 00:23:52 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/08 01:08:25 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Retorna o sprite correto baseado na direção do inimigo
int	get_enemy_sprite_index(t_enemy *enemy)
{
	if (enemy->movement_type == 0) // Horizontal
	{
		if (enemy->direction == 0) // Movendo para direita
			return (1); // Sans_right.xpm
		else // Movendo para esquerda  
			return (0); // Sans_left.xpm
	}
	else // Vertical - usa a última direção horizontal que teve
	{
		// Para movimento vertical, mantém o sprite baseado na última direção
		// ou usa um padrão (pode personalizar depois)
		return (enemy->last_horizontal_direction);
	}
}

// Atualiza o sprite do inimigo quando ele se move
void	update_enemy_sprite_on_movement(t_enemy *enemy)
{
	if (enemy->movement_type == 0) // Movimento horizontal
	{
		// Salva a direção horizontal para uso quando estiver em movimento vertical
		enemy->last_horizontal_direction = enemy->direction;
	}
	
	// O sprite será atualizado na renderização usando get_enemy_sprite_index()
}

// Renderiza inimigos com sprites baseados na direção
void	render_enemies_with_direction(t_game *game)
{
	int	i;
	int	sprite_index;
	int	x, y;

	if (!game->map->enemies_data)
		return;

	i = 0;
	while (i < game->map->enemies)
	{
		x = game->map->enemies_data[i].pos.x * TILE_SIZE;
		y = game->map->enemies_data[i].pos.y * TILE_SIZE;
		
		// Pega o índice do sprite baseado na direção
		sprite_index = get_enemy_sprite_index(&game->map->enemies_data[i]);
		
		// Renderiza o inimigo com o sprite correto
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures.enemies[sprite_index], x, y);
		
		i++;
	}
}
