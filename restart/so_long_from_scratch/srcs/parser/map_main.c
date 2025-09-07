/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:06:15 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/06 23:59:13 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Maps avaliables: %s <map_file.ber>\n", argv[0]);
		return (1);
	}
	ft_printf("🍳 Initializing So Long...\n");
	map = parse_map(argv[1]);
	validate_map(&map);
	print_map_info(&map);
	if (!init_graphics(&game, &map))
	{
		free_map(&map);
		throw_error("Failed to initialize graphics...");
	}
	load_textures(&game);
	//render_map(&game);
	render_static_map(&game);
	render_animated_entities(&game, 0);
	ft_printf("🏁Map loaded sucessfully! \n");
	ft_printf("   Size: %dx%d\n", map.width, map.height);
	mlx_loop_hook(game.mlx, animate_game, &game);
	mlx_hook(game.window, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	//free_map(&map);
	ft_printf("✅ Program completed without mlx_loop\n");
	return (0);
}
