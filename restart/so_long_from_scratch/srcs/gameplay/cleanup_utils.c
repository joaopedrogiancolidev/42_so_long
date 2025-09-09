/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:53:52 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/09 19:22:38 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Adicione estas funções AQUI:
void	cleanup_basic_textures(t_game *game)
{
	if (game->textures.wall)
		mlx_destroy_image(game->mlx, game->textures.wall);
	if (game->textures.floor)
		mlx_destroy_image(game->mlx, game->textures.floor);
	if (game->textures.exit)
		mlx_destroy_image(game->mlx, game->textures.exit);
	if (game->map)
	{
		free_map(game->map);
		game->map = NULL;
	}
}

void	cleanup_player_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->textures.player[i])
			mlx_destroy_image(game->mlx, game->textures.player[i]);
		i++;
	}
}

void	cleanup_entity_textures(t_game *game)
{
	if (game->textures.collectible[0])
		mlx_destroy_image(game->mlx, game->textures.collectible[0]);
	if (game->textures.collectible[1])
		mlx_destroy_image(game->mlx, game->textures.collectible[1]);
	if (game->textures.enemies[0])
		mlx_destroy_image(game->mlx, game->textures.enemies[0]);
	if (game->textures.enemies[1])
		mlx_destroy_image(game->mlx, game->textures.enemies[1]);
}

void	cleanup_window_and_display(t_game *game)
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

void	print_final_status(t_game *game)
{
	if (game->game_over && game->map->collectibles == 0)
		ft_printf("🏆 Status: VITÓRIA!\n");
	else if (game->game_over)
		ft_printf("💀 Status: GAME OVER!\n");
	else
		ft_printf("🚪 Status: Jogo interrompido\n");
}
