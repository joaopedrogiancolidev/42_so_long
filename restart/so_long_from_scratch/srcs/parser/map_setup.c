/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:48:45 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/09 17:55:55 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	setup_map(t_map *map, char *filename)
{
	if (!filename)
		return (0);
	*map = parse_map(filename);
	validate_map(map);
	print_map_info(map);
	return (1);
}

int	setup_graphics(t_game *game, t_map *map)
{
	if (!init_graphics(game, map))
	{
		free_map(map);
		throw_error("Falha ao inicializar gráficos");
		return (0);
	}
	load_textures(game);
	return (1);
}

void	start_game_loop(t_game *game)
{
	mlx_loop_hook(game->mlx, animate_game, game);
	mlx_hook(game->window, 2, 1L << 0, key_press, game);
	mlx_hook(game->window, 17, 0, close_game, game);
	ft_printf("🎬 Iniciando loop principal do jogo...\n\n");
	mlx_loop(game->mlx);
	ft_printf("⚠️ Saída inesperada do mlx_loop\n");
}
