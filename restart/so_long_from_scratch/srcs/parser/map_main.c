/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:06:15 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/07 18:59:46 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// int	close_game(t_game *game)
// {
// 	mlx_destroy_window(game->mlx, game->window);
// 	exit(0);
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	t_map	map;
// 	t_game	game;

// 	if (argc != 2)
// 	{
// 		ft_printf("Maps avaliables: %s <map_file.ber>\n", argv[0]);
// 		return (1);
// 	}
// 	ft_printf("🍳 Initializing So Long...\n");
// 	map = parse_map(argv[1]);
// 	validate_map(&map);
// 	print_map_info(&map);
// 	if (!init_graphics(&game, &map))
// 	{
// 		free_map(&map);
// 		throw_error("Failed to initialize graphics...");
// 	}
// 	load_textures(&game);
// 	//render_map(&game);
// 	render_static_map(&game);
// 	render_animated_entities(&game, 0);
// 	ft_printf("🏁Map loaded sucessfully! \n");
// 	ft_printf("   Size: %dx%d\n", map.width, map.height);
// 	mlx_loop_hook(game.mlx, animate_game, &game);
// 	mlx_hook(game.window, 17, 0, close_game, &game);
// 	mlx_loop(game.mlx);
// 	//free_map(&map);
// 	ft_printf("✅ Program completed without mlx_loop\n");
// 	return (0);
// }

void	init_game_state(t_game *game)
{
	game->moves = 0;
	game->collected = 0;
	game->game_over = 0;
	game->frame_count = 0;
	game->needs_rerender = 1; // Força primeira renderização
	
	ft_printf("🎮 Estado inicial do jogo:\n");
	ft_printf("   • Movimentos: %d\n", game->moves);
	ft_printf("   • Collectibles para coletar: %d\n", game->map->collectibles);
	ft_printf("   • Posição inicial: (%d, %d)\n", 
		game->map->player_pos.x, game->map->player_pos.y);
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

	// Validação de argumentos
	if (argc != 2)
	{
		ft_printf("❌ Uso: %s <map_file.ber>\n", argv[0]);
		return (1);
	}
	
	ft_printf("🚀 Inicializando So_long...\n");
	
	// Parse e validação do mapa
	map = parse_map(argv[1]);
	validate_map(&map);
	print_map_info(&map);
	
	// Inicialização gráfica
	if (!init_graphics(&game, &map))
	{
		free_map(&map);
		throw_error("Falha ao inicializar gráficos");
	}
	
	// Carregamento das texturas
	load_textures(&game);
	
	// Inicialização do estado do jogo
	init_game_state(&game);
	
	// Renderização inicial
	render_static_map(&game);
	render_animated_entities(&game, 0);
	
	// Informações para o jogador
	print_controls();
	ft_printf("✅ Jogo carregado com sucesso!\n");
	ft_printf("📏 Tamanho do mapa: %dx%d\n", map.width, map.height);
	
	// Setup dos hooks do MLX
	mlx_loop_hook(game.mlx, animate_game, &game);           // Animação contínua
	mlx_hook(game.window, 2, 1L<<0, key_press, &game);     // KeyPress event
	mlx_hook(game.window, 17, 0, close_game, &game);       // Window close event
	
	ft_printf("🎬 Iniciando loop principal do jogo...\n\n");
	
	// Loop principal
	mlx_loop(game.mlx);
	
	// Este código nunca deveria ser executado devido ao mlx_loop
	ft_printf("⚠️  Saída inesperada do mlx_loop\n");
	//cleanup_game(&game);
	return (0);
}
