/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_positions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:24:26 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/05 17:52:39 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	find_positions(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'P')
			{
				map->player_pos.x = x;
				map->player_pos.y = y;
			}
			else if (map->grid[y][x] == 'E')
			{
				map->exit_pos.x = x;
				map->exit_pos.y = y;
			}
			x++;
		}
		y++;
	}
}
