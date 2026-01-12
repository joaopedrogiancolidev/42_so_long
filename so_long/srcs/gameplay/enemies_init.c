/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 22:26:40 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/09 22:48:57 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	init_single_enemy(t_enemy *enemy, int enemy_count)
{
	if (enemy_count % 2 == 0)
	{
		enemy->movement_type = 0;
		enemy->direction = 0;
		enemy->last_horizontal_direction = 0;
	}
	else
	{
		enemy->movement_type = 1;
		enemy->direction = 2;
		enemy->last_horizontal_direction = 0;
	}
}

static void	process_map_cell(t_game *game, int y, int x, int *enemy_count)
{
	if (game->map->grid[y][x] == 'M')
	{
		game->map->enemies_data[*enemy_count].pos.x = x;
		game->map->enemies_data[*enemy_count].pos.y = y;
		init_single_enemy(&game->map->enemies_data[*enemy_count], *enemy_count);
		(*enemy_count)++;
	}
}

static void	scan_map_for_enemies(t_game *game)
{
	int	y;
	int	x;
	int	enemy_count;

	enemy_count = 0;
	y = -1;
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
			process_map_cell(game, y, x, &enemy_count);
	}
}

void	init_enemies(t_game *game)
{
	if (!game || !game->map)
	{
		ft_printf("❌ ERROR: game or map is NULL\n");
		return ;
	}
	if (game->map->enemies == 0)
	{
		game->map->enemies_data = NULL;
		return ;
	}
	game->map->enemies_data = malloc(sizeof(t_enemy) * game->map->enemies);
	if (!game->map->enemies_data)
		throw_error("Failed into find enemies");
	scan_map_for_enemies(game);
}
