/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:40:32 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/02 17:25:57 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// t_game	init_game(char *map_file);
// void	init_textures(t_game *game);

t_game	init_game(char *map_file)
{
	t_game	game;

	game.map = parse_map(map_file);
	game.moves = 0;
	game.collected = 0;
	game.game_over = 0;
	return (game);
}

void	start_game(t_game *game)
{
	// Placeholder - será implementado depois
	printf("Game started with map size: %dx%d\n", 
		game->map.width, game->map.height);
}