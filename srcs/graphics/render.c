/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:42:16 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/02 19:43:44 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// int		render_frame(t_game *game);
// void	render_map(t_game *game);
// void	render_player(t_game *game);

// Função para renderizar o mapa
// Função para renderizar o mapa
int render_frame(t_game *game)
{
    // Limpa a janela
    mlx_clear_window(game->mlx, game->window);
    
    // Cores (RGB)
    int wall_color = 0x0000FF;        // Azul para paredes
    int player_color = 0xFF0000;      // Vermelho para jogador  
    int collectible_color = 0x00FF00; // Verde para coletáveis
    int exit_color = 0xFFFF00;        // Amarelo para saída
    int floor_color = 0x888888;       // Cinza para chão
    
    int y = 0;
    while (y < game->map.height)
    {
        int x = 0;
        while (x < game->map.width)
        {
            char tile = game->map.grid[y][x];
            int color;
            
            // Escolhe a cor baseada no tile
            if (tile == '1') color = wall_color;
            else if (tile == 'P') color = player_color;
            else if (tile == 'C') color = collectible_color;
            else if (tile == 'E') color = exit_color;
            else color = floor_color;
            
            // Desenha um quadrado representando o tile
            int i = 0;
            while (i < 64)  // 64px de altura
            {
                int j = 0;
                while (j < 64)  // 64px de largura
                {
                    mlx_pixel_put(game->mlx, game->window, x * 64 + j, y * 64 + i, color);
                    j++;
                }
                i++;
            }
            
            // Mostra também o caractere no centro
            mlx_string_put(game->mlx, game->window, x * 64 + 28, y * 64 + 32, 0x000000, &tile);
            x++;
        }
        y++;
    }
    
    return (0);
}
