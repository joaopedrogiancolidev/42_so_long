/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 22:27:27 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/09 23:39:03 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	move_enemies(t_game *game)
{
	static int	enemy_move_counter = 0;
	int			i;

	enemy_move_counter++;
	if (enemy_move_counter < 600)
		return ;
	enemy_move_counter = 0;
	if (!game || !game->map)
		return ;
	if (game->map->enemies == 0 || !game->map->enemies_data)
		return ;
	i = 0;
	while (i < game->map->enemies)
	{
		move_single_enemy(game, i);
		i++;
	}
	check_player_collision(game);
	game->needs_rerender = 1;
}
