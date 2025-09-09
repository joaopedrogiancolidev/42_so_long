/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:57:08 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/09 20:57:11 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	print_final_stats(t_game *game)
{
	ft_printf("📊 Estatísticas finais:\n");
	ft_printf("   • Movimentos: %d\n", game->moves);
	ft_printf("   • Collectibles coletados: %d\n", game->collected);
	if (game->game_over && game->map->collectibles == 0)
		ft_printf("🏆 Status: VITÓRIA!\n");
	else if (game->game_over)
		ft_printf("💀 Status: GAME OVER!\n");
	else
		ft_printf("🚪 Status: Jogo interrompido\n");
}

int	close_game(t_game *game)
{
	ft_printf("\n🎮 Encerrando So_long...\n");
	print_final_stats(game);
	cleanup_game(game);
	ft_printf("👋 Obrigado por jogar!\n");
	exit(0);
	return (0);
}
