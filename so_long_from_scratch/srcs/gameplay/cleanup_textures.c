/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:56:36 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/09 22:47:43 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	cleanup_player_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->textures.player[i])
		{
			mlx_destroy_image(game->mlx, game->textures.player[i]);
			game->textures.player[i] = NULL;
		}
		i++;
	}
}

static void	cleanup_collectible_textures(t_game *game)
{
	if (game->textures.collectible[0])
	{
		mlx_destroy_image(game->mlx, game->textures.collectible[0]);
		game->textures.collectible[0] = NULL;
	}
	if (game->textures.collectible[1])
	{
		mlx_destroy_image(game->mlx, game->textures.collectible[1]);
		game->textures.collectible[1] = NULL;
	}
}

static void	cleanup_enemy_textures(t_game *game)
{
	if (game->textures.enemies[0])
	{
		mlx_destroy_image(game->mlx, game->textures.enemies[0]);
		game->textures.enemies[0] = NULL;
	}
	if (game->textures.enemies[1])
	{
		mlx_destroy_image(game->mlx, game->textures.enemies[1]);
		game->textures.enemies[1] = NULL;
	}
}

static void	cleanup_basic_textures(t_game *game)
{
	if (game->textures.wall)
	{
		mlx_destroy_image(game->mlx, game->textures.wall);
		game->textures.wall = NULL;
	}
	if (game->textures.floor)
	{
		mlx_destroy_image(game->mlx, game->textures.floor);
		game->textures.floor = NULL;
	}
	if (game->textures.exit)
	{
		mlx_destroy_image(game->mlx, game->textures.exit);
		game->textures.exit = NULL;
	}
}

void	cleanup_textures(t_game *game)
{
	if (!game || !game->mlx)
		return ;
	ft_printf("🧹 Cleaning textures...\n");
	cleanup_basic_textures(game);
	cleanup_player_textures(game);
	cleanup_collectible_textures(game);
	cleanup_enemy_textures(game);
}
