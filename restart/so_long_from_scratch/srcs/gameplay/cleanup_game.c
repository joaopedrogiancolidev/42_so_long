/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:56:53 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/09 20:56:56 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	cleanup_mlx_resources(t_game *game)
{
	if (game->window && game->mlx)
	{
		mlx_destroy_window(game->mlx, game->window);
		game->window = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

static void	cleanup_map_resources(t_game *game)
{
	if (game->map && game->map->enemies_data && game->map->enemies > 0)
	{
		free(game->map->enemies_data);
		game->map->enemies_data = NULL;
	}
	if (game->map)
	{
		free_map(game->map);
		game->map = NULL;
	}
}

void	cleanup_game(t_game *game)
{
	if (!game)
		return ;
	ft_printf("🧽 Iniciando limpeza completa do jogo...\n");
	cleanup_map_resources(game);
	cleanup_textures(game);
	cleanup_mlx_resources(game);
	ft_printf("✅ Limpeza completa finalizada\n");
}
