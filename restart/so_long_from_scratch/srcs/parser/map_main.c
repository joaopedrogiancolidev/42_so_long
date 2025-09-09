/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:06:15 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/09 17:49:25 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_game_state(t_game *game)
{
	game->moves = 0;
	game->collected = 0;
	game->game_over = 0;
	game->frame_count = 0;
	game->needs_rerender = 1;
	game->player_direction = DOWN;
	ft_printf("🎮 Estado inicial do jogo:\n");
	ft_printf("   • Movimentos: %d\n", game->moves);
	ft_printf("   • Collectibles para coletar: %d\n", game->map->collectibles);
	ft_printf("   • Posição inicial: (%d, %d)\n",
		game->map->player_pos.x, game->map->player_pos.y);
	ft_printf("   • Inimigos no mapa: %d\n", game->map->enemies);
}

void	print_controls(void)
{
	ft_printf("\n🎮 CONTROLES DO JOGO:\n");
	ft_printf("   • WASD ou Arrow Keys: Mover player\n");
	ft_printf("   • ESC: Sair do jogo\n");
	ft_printf("\n🎯 OBJETIVO:\n");
	ft_printf("   • Colete todos os itens (C)\n");
	ft_printf("   • Vá para a saída (E)\n");
	ft_printf("   • Evite os inimigos (M)\n\n");
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	if (argc != 2)
		return (ft_printf("❌ Uso: %s <map.ber>\n", argv[0]), 1);
	ft_printf("🚀 Inicializando So_long...\n");
	if (!setup_map(&map, argv[1]) || !setup_graphics(&game, &map))
		return (1);
	init_game_state(&game);
	ft_printf("🤖 Inicializando inimigos...\n");
	init_enemies(&game);
	render_static_map(&game);
	render_animated_entities(&game, 0);
	render_full_hud(&game);
	print_controls();
	ft_printf("✅ Jogo carregado! Tamanho: %dx%d\n", map.width, map.height);
	start_game_loop(&game);
	return (0);
}
