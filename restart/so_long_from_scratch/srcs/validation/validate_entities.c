/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_entities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:27:32 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/05 16:01:36 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	validate_entities_count(t_map *map)
{
	if (map->players != 1)
		throw_error("Map must have exactly one player!");
	if (map->exits != 1)
		throw_error("Map must have exactly one exit!");
	if (map->collectibles < 1)
		throw_error("Map must have at least one collectible");
}

void	validate_entities(t_map *map)
{
	int		y;
	int		x;

	map->players = 0;
	map->exits = 0;
	map->collectibles = 0;
	map->enemies = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'P')
				map->players++;
			else if (map->grid[y][x] == 'E')
				map->exits++;
			else if (map->grid[y][x] == 'C')
				map->collectibles++;
			else if (map->grid[y][x] == 'M')
				map->enemies++;
			x++;
		}
		y++;
	}
}
