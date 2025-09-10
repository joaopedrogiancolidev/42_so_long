/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:06:15 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/10 00:16:47 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	init_game_state(t_game *game)
{
	game->moves = 0;
	game->collected = 0;
	game->game_over = 0;
	game->frame_count = 0;
	game->needs_rerender = 1;
	game->player_direction = DOWN;
	ft_printf("🎮 Game initial state:\n");
	ft_printf("   • Moves: %d\n", game->moves);
	ft_printf("   • Collectibles: %d\n", game->map->collectibles);
	ft_printf("   • Initial position: (%d, %d)\n",
		game->map->player_pos.x, game->map->player_pos.y);
	ft_printf("   • Enemies on map: %d\n", game->map->enemies);
}

static void	print_controls(void)
{
	ft_printf("\n🎮 Game Controls:\n");
	ft_printf("   • WASD or Arrow Keys: Move player\n");
	ft_printf("   • ESC: Exit game\n");
	ft_printf("\n🎯 OBJECTIVE:\n");
	ft_printf("   • Collect all items\n");
	ft_printf("   • Go to the exit\n");
	ft_printf("   • Avoid the enemies\n\n");
}

static int	init_game(t_game *game, t_map *map, char *map_file)
{
	ft_printf("🚀 Initializing So_long...\n");
	*map = parse_map(map_file);
	validate_map(map);
	print_map_info(map);
	if (!init_graphics(game, map))
	{
		free_map(map);
		throw_error("Failed to initialize graphics");
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
	ft_printf("✅ Game loaded successfully!\n");
	ft_printf("📏  Map size: %dx%d\n",
		game->map->width, game->map->height);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	if (argc != 2)
		return (ft_printf("❌ Usage: %s <map_file.ber>\n", argv[0]), 1);
	if (!init_game(&game, &map, argv[1]))
		return (1);
	load_game_content(&game);
	mlx_loop_hook(game.mlx, animate_game, &game);
	mlx_hook(game.window, 2, 1L << 0, key_press, &game);
	mlx_hook(game.window, 17, 0, close_game, &game);
	ft_printf("🎬 Starting main game loop...\n\n");
	mlx_loop(game.mlx);
	ft_printf("⚠️ Unexpected exit from mlx_loop\n");
	return (0);
}
