/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 21:05:50 by jgiancol          #+#    #+#             */
/*   Updated: 2025/11/03 13:04:33 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	handle_movement_keys(int keycode, t_game *game,
	int *new_x, int *new_y)
{
	if (keycode == W_KEY || keycode == UP_KEY)
	{
		*new_y -= 1;
		game->player_direction = UP;
	}
	else if (keycode == S_KEY || keycode == DOWN_KEY)
	{
		*new_y += 1;
		game->player_direction = DOWN;
	}
	else if (keycode == A_KEY || keycode == LEFT_KEY)
	{
		*new_x -= 1;
		game->player_direction = LEFT;
	}
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
	{
		*new_x += 1;
		game->player_direction = RIGHT;
	}
}

int	key_press(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->map->player_pos.x;
	new_y = game->map->player_pos.y;
	if (game->game_over && keycode == ESC_KEY)
		close_game(game);
	if (game->game_over)
		return (0);
	if (keycode == ESC_KEY)
		close_game(game);
	else
		handle_movement_keys(keycode, game, &new_x, &new_y);
	if (new_x != game->map->player_pos.x || new_y != game->map->player_pos.y)
		move_player(game, new_x, new_y);
	else
		game->needs_rerender = 1;
	return (0);
}
