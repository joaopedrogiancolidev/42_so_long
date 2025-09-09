/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:44:31 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/09 19:48:39 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	calculate_new_position(t_enemy *enemy, int *new_x, int *new_y)
{
	if (enemy->movement_type == 0)
	{
		if (enemy->direction == 0)
			(*new_x)++;
		else
			(*new_x)--;
	}
	else
	{
		if (enemy->direction == 2)
			(*new_y)++;
		else
			(*new_y)--;
	}
}

void	execute_enemy_movement(t_game *game, t_enemy *enemy,
			int old_x, int old_y)
{
	int	new_x;
	int	new_y;

	new_x = enemy->pos.x;
	new_y = enemy->pos.y;
	if (can_enemy_move(game, new_x, new_y))
	{
		game->map->grid[old_y][old_x] = '0';
		game->map->grid[new_y][new_x] = 'M';
		enemy->pos.x = new_x;
		enemy->pos.y = new_y;
	}
}

void	reverse_enemy_direction(t_enemy *enemy)
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

void	check_player_collision(t_game *game)
{
	int	i;

	if (!game->map->enemies_data)
		return ;
	i = 0;
	while (i < game->map->enemies)
	{
		if (game->map->enemies_data[i].pos.x == game->map->player_pos.x
			&& game->map->enemies_data[i].pos.y == game->map->player_pos.y)
		{
			ft_printf("💀 Game Over! Você foi pego por um inimigo!\n");
			game->game_over = 1;
			close_game(game);
			return ;
		}
		i++;
	}
}
