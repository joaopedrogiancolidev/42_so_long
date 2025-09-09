/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:33:08 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/09 17:33:10 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_player_collision(t_game *game)
{
	int	i;

	if (!game->map->enemies_data)
		return ;
	i = 0;
	while (i < game->map->enemies)
	{
		if (game->map->enemies_data[i].pos.x == game->map->player_pos.x &&
			game->map->enemies_data[i].pos.y == game->map->player_pos.y)
		{
			ft_printf("Game Over! You were caught by an enemy!\n");
			game->game_over = 1;
			close_game(game);
			return ;
		}
		i++;
	}
}

static int	should_move_enemies(void)
{
	static int	enemy_move_counter = 0;

	enemy_move_counter++;
	if (enemy_move_counter < 600)
		return (0);
	ft_printf("Moving all enemies! Frame: %d\n", enemy_move_counter);
	enemy_move_counter = 0;
	return (1);
}

static int	validate_enemy_data(t_game *game)
{
	if (!game || !game->map)
	{
		ft_printf("game or map is NULL in move_enemies\n");
		return (0);
	}
	if (game->map->enemies == 0 || !game->map->enemies_data)
	{
		ft_printf("No enemies or enemies_data is NULL\n");
		return (0);
	}
	return (1);
}

void	move_enemies(t_game *game)
{
	int	i;

	if (!should_move_enemies())
		return ;
	if (!validate_enemy_data(game))
		return ;
	i = 0;
	while (i < game->map->enemies)
	{
		move_single_enemy(game, i);
		i++;
	}
	check_player_collision(game);
	game->needs_rerender = 1;
	ft_printf("Rendering marked as necessary\n");
}
