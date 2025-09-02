/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:40:32 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/02 19:43:16 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_game init_game(char *map_file)
{
    t_game game;
    
    game.map = parse_map(map_file);
    game.moves = 0;
    game.collected = 0;
    game.game_over = 0;
    
    init_mlx(&game);
    
    return (game);
}

void start_game(t_game *game)
{
    printf("🚀 Game started successfully!\n");
    printf("🗺️  Map size: %dx%d\n", game->map.width, game->map.height);
    
    // Inicia o loop gráfico da MiniLibX
    mlx_loop_hook(game->mlx, render_frame, game);
    mlx_loop(game->mlx);
}
