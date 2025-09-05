/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:31:15 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/05 15:01:20 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_map	parse_map(char *filename)
{
	t_map	map;

	map = init_map_struct();
	if (!get_map_height_width(filename, &map))
		throw_error("Map is empty or invalid");
	map.grid = ft_calloc(map.height + 1, sizeof(char *));
	if (!map.grid)
		throw_error("Memory allocation failed");
	fill_map_grid(filename, &map);
	return (map);
}

void	print_map_info(t_map *map)
{
	int	y;

	ft_printf("🎮   Map Info:\n");
	ft_printf("🎮   Size: %dx%d\n", map->width, map->height);
	ft_printf("🎮   Collectibles: %d\n", map->collectibles);
	ft_printf("🎮   Exits: %d\n", map->exits);
	ft_printf("🎮   Players: %d\n", map->players);
	ft_printf("🎮   Grid:\n");
	y = 0;
	while (y < map->height)
	{
		ft_printf("      %s\n", map->grid[y]);
		y++;
	}
}
