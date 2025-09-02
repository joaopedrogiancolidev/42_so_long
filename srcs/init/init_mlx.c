/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:41:42 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/02 19:43:14 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/so_long.h"

void init_mlx(t_game *game)
{
    // Inicializa a MiniLibX
    game->mlx = mlx_init();
    if (!game->mlx)
        throw_error("Failed to initialize MLX");
    
    // Calcula o tamanho da janela baseado no mapa
    int window_width = game->map.width * 64;  // 64px por tile
    int window_height = game->map.height * 64;
    
    // Cria a janela
    game->window = mlx_new_window(game->mlx, window_width, window_height, "So Long");
    if (!game->window)
        throw_error("Failed to create window");
    
    printf("🖥️  Janela MLX criada: %dx%d\n", window_width, window_height);
}