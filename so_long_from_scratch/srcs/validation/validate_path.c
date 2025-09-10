/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:15:07 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/05 17:51:46 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	flood_fill(t_map *map, int y, int x, char **visited)
{
	if (y < 0 || y >= map->height || x < 0 || x >= map->width)
		return ;
	if (map->grid[y][x] == '1' || visited[y][x] == '1')
		return ;
	visited[y][x] = '1';
	flood_fill(map, y - 1, x, visited);
	flood_fill(map, y + 1, x, visited);
	flood_fill(map, y, x - 1, visited);
	flood_fill(map, y, x + 1, visited);
}

static int	can_reach_exit_and_collectibles(t_map *map, char **visited)
{
	int		y;
	int		x;

	if (visited[map->exit_pos.y][map->exit_pos.x] != '1')
		return (0);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'C' && visited[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	validate_path(t_map *map)
{
	char	**visited;
	int		i;
	int		valid;

	visited = ft_calloc(map->height + 1, sizeof(char *));
	i = -1;
	while (++i < map->height)
		visited[i] = ft_calloc(map->width + 1, sizeof(char));
	flood_fill(map, map->player_pos.y, map->player_pos.x, visited);
	valid = can_reach_exit_and_collectibles(map, visited);
	i = -1;
	while (++i < map->height)
		free(visited[i]);
	free(visited);
	if (!valid)
		throw_error("No valid path to exit or collectibles");
}
