/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:53:52 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/08 00:47:22 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	cleanup_textures(t_game *game)
{
	if (!game || !game->mlx)
		return;

	ft_printf("🧹 Limpando texturas...\n");

	// Limpa texturas estáticas
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

	// Limpa texturas animadas do player
	if (game->textures.player[0])
	{
		mlx_destroy_image(game->mlx, game->textures.player[0]);
		game->textures.player[0] = NULL;
	}
	if (game->textures.player[1])
	{
		mlx_destroy_image(game->mlx, game->textures.player[1]);
		game->textures.player[1] = NULL;
	}

	// Limpa texturas animadas dos collectibles
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

	// Limpa texturas animadas dos inimigos
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

void cleanup_game(t_game *game)
{
    if (!game)
        return;

    ft_printf("🧽 Iniciando limpeza completa do jogo...\n");

    // Clean enemies data BEFORE freeing map
    if (game->map && game->map->enemies_data && game->map->enemies > 0)
    {
        free(game->map->enemies_data);
        game->map->enemies_data = NULL;
    }

    // Clean textures
    cleanup_textures(game);

    // Destroy window
    if (game->window && game->mlx)
    {
        mlx_destroy_window(game->mlx, game->window);
        game->window = NULL;
    }

    // Clean map
    if (game->map)
    {
        free_map(game->map);
        game->map = NULL; // Set to NULL after freeing
    }

    // Clean MLX
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
        game->mlx = NULL;
    }

    ft_printf("✅ Limpeza completa finalizada\n");
}

int	close_game(t_game *game)
{
	ft_printf("\n🎮 Encerrando So_long...\n");
	ft_printf("📊 Estatísticas finais:\n");
	ft_printf("   • Movimentos: %d\n", game->moves);
	ft_printf("   • Collectibles coletados: %d\n", game->collected);
	
	if (game->game_over && game->map->collectibles == 0)
		ft_printf("🏆 Status: VITÓRIA!\n");
	else if (game->game_over)
		ft_printf("💀 Status: GAME OVER!\n");
	else
		ft_printf("🚪 Status: Jogo interrompido\n");

	// Limpa recursos
	cleanup_game(game);
	
	ft_printf("👋 Obrigado por jogar!\n");
	exit(0);
	return (0);
}
