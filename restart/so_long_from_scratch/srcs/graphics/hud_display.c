/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 00:19:17 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/08 00:19:36 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_hud_background(t_game *game)
{
	int	x;
	int	y;
	
	// Cria um fundo semi-transparente para o HUD
	// Desenha retângulo preto no canto superior esquerdo
	y = 0;
	while (y < 40) // Altura do HUD
	{
		x = 0;
		while (x < 200) // Largura do HUD
		{
			mlx_pixel_put(game->mlx, game->window, x, y, 0x000000); // Preto
			x++;
		}
		y++;
	}
}

void	render_moves_counter(t_game *game)
{
	char	*moves_str;
	char	*display_text;
	char	*temp;
	
	// Converte número de movimentos para string
	moves_str = ft_itoa(game->moves);
	if (!moves_str)
		return;
	
	// Cria texto de display
	temp = ft_strjoin("Moves: ", moves_str);
	free(moves_str);
	
	if (!temp)
		return;
		
	display_text = temp;
	
	// Renderiza o fundo do HUD primeiro
	render_hud_background(game);
	
	// Renderiza o texto em branco no canto superior esquerdo
	mlx_string_put(game->mlx, game->window, 10, 20, 0xFFFFFF, display_text);
	
	free(display_text);
}

void	render_collectibles_counter(t_game *game)
{
	char	*collectibles_str;
	char	*display_text;
	char	*temp;
	
	// Converte número de collectibles para string
	collectibles_str = ft_itoa(game->map->collectibles);
	if (!collectibles_str)
		return;
	
	// Cria texto de display
	temp = ft_strjoin("Items: ", collectibles_str);
	free(collectibles_str);
	
	if (!temp)
		return;
		
	display_text = temp;
	
	// Renderiza o texto abaixo do contador de movimentos
	mlx_string_put(game->mlx, game->window, 10, 35, 0xFFFFFF, display_text);
	
	free(display_text);
}

void	render_full_hud(t_game *game)
{
	if (!game || !game->mlx || !game->window)
		return;
	
	// Renderiza fundo do HUD
	render_hud_background(game);
	
	// Renderiza contador de movimentos
	render_moves_counter(game);
	
	// Renderiza contador de collectibles (opcional)
	render_collectibles_counter(game);
}
