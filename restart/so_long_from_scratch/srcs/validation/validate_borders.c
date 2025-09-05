/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_borders.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:39:56 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/05 16:00:04 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	validate_vertical_borders(t_map *map)
{
	int		y;

	y = 0;
	while (y < map->height)
	{
		if (map->grid[y][0] != '1')
			throw_error("Left borders must be walls...");
		if (map->grid[y][map->width - 1] != '1')
			throw_error("Right border must be walls...");
		y++;
	}
}

static void	validate_horizontal_borders(t_map *map)
{
	int		x;

	x = 0;
	while (x < map->width)
	{
		if (map->grid[0][x] != '1')
			throw_error("Top border must be walls...");
		if (map->grid[map->height - 1][x] != '1')
			throw_error("Bottom border must be walls...");
		x++;
	}
}

void	validate_borders(t_map *map)
{
	validate_vertical_borders(map);
	validate_horizontal_borders(map);
}
