/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_collision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 22:27:13 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/09 22:41:24 by jgiancol         ###   ########.fr       */
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
