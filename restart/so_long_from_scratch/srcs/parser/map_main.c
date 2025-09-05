/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:06:15 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/05 18:41:34 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Maps avaliables: %s <map_file.ber>\n", argv[0]);
		return (1);
	}
	ft_printf("🍳 Inicializing So Long...\n");
	map = parse_map(argv[1]);
	validate_map(&map);
	print_map_info(&map);
	if (!init_graphics(&game, &map))
	{
		free_map(&map);
		throw_error("Failed to initialize graphics...");
	}
	ft_printf("🏁Map loaded sucessfully! \n");
	ft_printf("   Size: %dx%d\n", map.width, map.height);
	mlx_loop(game.mlx);
	//free_map(&map);
	return (0);
}
