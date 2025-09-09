/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 00:23:52 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/09 18:21:07 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	get_enemy_sprite_index(t_enemy *enemy)
{
	if (enemy->movement_type == 0)
	{
		if (enemy->direction == 0)
			return (1);
		else
			return (0);
	}
	else
	{
		return (enemy->last_horizontal_direction);
	}
}

void	update_enemy_sprite_on_movement(t_enemy *enemy)
{
	if (enemy->movement_type == 0)
	{
		enemy->last_horizontal_direction = enemy->direction;
	}
}

void	render_enemies_with_direction(t_game *game)
{
	int	sprite_index;
	int	x;
	int	y;
	int	i;

	i = 0;
	if (!game->map->enemies_data)
		return ;
	while (i < game->map->enemies)
	{
		x = game->map->enemies_data[i].pos.x * TILE_SIZE;
		y = game->map->enemies_data[i].pos.y * TILE_SIZE;
		sprite_index = get_enemy_sprite_index(&game->map->enemies_data[i]);
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures.enemies[sprite_index], x, y);
		i++;
	}
}
