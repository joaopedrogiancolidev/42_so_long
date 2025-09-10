/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:34:44 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/09 22:30:48 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	can_enemy_move(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map->width)
		return (0);
	if (y < 0 || y >= game->map->height)
		return (0);
	if (game->map->grid[y][x] == '1')
		return (0);
	if (game->map->grid[y][x] == 'M')
		return (0);
	return (1);
}

static void	calculate_new_position(t_enemy *enemy, int *new_x, int *new_y)
{
	*new_x = enemy->pos.x;
	*new_y = enemy->pos.y;
	if (enemy->movement_type == 0)
	{
		if (enemy->direction == 0)
			*new_x += 1;
		else
			*new_x -= 1;
	}
	else
	{
		if (enemy->direction == 2)
			*new_y += 1;
		else
			*new_y -= 1;
	}
}

static void	handle_enemy_movement(t_game *game, t_enemy *enemy,
	int new_x, int new_y)
{
	if (can_enemy_move(game, new_x, new_y))
	{
		game->map->grid[enemy->pos.y][enemy->pos.x] = '0';
		game->map->grid[new_y][new_x] = 'M';
		enemy->pos.x = new_x;
		enemy->pos.y = new_y;
		update_enemy_sprite_on_movement(enemy);
	}
}

static void	change_enemy_direction(t_enemy *enemy)
{
	if (enemy->movement_type == 0)
	{
		if (enemy->direction == 0)
			enemy->direction = 1;
		else
			enemy->direction = 0;
	}
	else
	{
		if (enemy->direction == 2)
			enemy->direction = 3;
		else
			enemy->direction = 2;
	}
}

void	move_single_enemy(t_game *game, int enemy_index)
{
	t_enemy	*enemy;
	int		new_x;
	int		new_y;

	if (enemy_index >= game->map->enemies)
		return ;
	enemy = &game->map->enemies_data[enemy_index];
	calculate_new_position(enemy, &new_x, &new_y);
	if (can_enemy_move(game, new_x, new_y))
		handle_enemy_movement(game, enemy, new_x, new_y);
	else
		change_enemy_direction(enemy);
}
