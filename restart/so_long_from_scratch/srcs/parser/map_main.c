/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:06:15 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/09 20:32:30 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

#include "../../includes/so_long.h"

static void	init_game_state(t_game *game)
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

static void	print_controls(void)
{
	ft_printf("\n🎮 CONTROLES DO JOGO:\n");
	ft_printf("   • WASD ou Arrow Keys: Mover player\n");
	ft_printf("   • ESC: Sair do jogo\n");
	ft_printf("\n🎯 OBJETIVO:\n");
	ft_printf("   • Colete todos os itens (C)\n");
	ft_printf("   • Vá para a saída (E)\n");
	ft_printf("   • Evite os inimigos (M)\n\n");
}

static int	init_game(t_game *game, t_map *map, char *map_file)
{
	ft_printf("🚀 Inicializando So_long...\n");
	*map = parse_map(map_file);
	validate_map(map);
	print_map_info(map);
	if (!init_graphics(game, map))
	{
		free_map(map);
		throw_error("Falha ao inicializar gráficos");
	}
	return (1);
}

static void	load_game_content(t_game *game)
{
	load_textures(game);
	init_game_state(game);
	init_enemies(game);
	render_static_map(game);
	render_animated_entities(game, 0);
	render_full_hud(game);
	print_controls();
	ft_printf("✅ Jogo carregado com sucesso!\n");
	ft_printf("📏 Tamanho do mapa: %dx%d\n",
		game->map->width, game->map->height);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	if (argc != 2)
		return (ft_printf("❌ Uso: %s <map_file.ber>\n", argv[0]), 1);
	if (!init_game(&game, &map, argv[1]))
		return (1);
	load_game_content(&game);
	mlx_loop_hook(game.mlx, animate_game, &game);
	mlx_hook(game.window, 2, 1L << 0, key_press, &game);
	mlx_hook(game.window, 17, 0, close_game, &game);
	ft_printf("🎬 Iniciando loop principal do jogo...\n\n");
	mlx_loop(game.mlx);
	ft_printf("⚠️ Saída inesperada do mlx_loop\n");
	return (0);
}
