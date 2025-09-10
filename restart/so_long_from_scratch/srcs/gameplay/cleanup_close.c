/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:57:08 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/09 22:58:38 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	print_final_stats(t_game *game)
{
	ft_printf("📊 Final statistics:\n");
	ft_printf("   • Movements: %d\n", game->moves);
	ft_printf("   • Collectibles collected: %d\n", game->collected);
	if (game->game_over && game->map->collectibles == 0)
		ft_printf("✴️ Status: DETERMINATION!!\n");
	else if (game->game_over)
		ft_printf("💀 Status: GAME OVER!\n");
	else
		ft_printf("🚪 Status: GAME PAUSE\n");
}

int	close_game(t_game *game)
{
	ft_printf("\n🎮 Closing So_long...\n");
	print_final_stats(game);
	cleanup_game(game);
	ft_printf("👋 Thank you for playing!\n");
	exit(0);
	return (0);
}
