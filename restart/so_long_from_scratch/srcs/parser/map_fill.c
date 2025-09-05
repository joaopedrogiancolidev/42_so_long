/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:42:38 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/05 14:07:41 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	process_line(char *line, t_map *map)
{
	if (map->height == 0 && ft_strlen(line) > 0)
	{
		map->width = ft_strlen(line);
		if (line[map->width - 1] == '\n')
			map->width--;
	}
	map->height++;
	free(line);
}

int	get_map_height_width(char *filename, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		throw_error("Cannot open map file");
	line = get_next_line(fd);
	while (line != NULL)
	{
		process_line(line, map);
		line = get_next_line(fd);
	}
	close(fd);
	return (map->height > 0 && map->width > 0);
}

void	process_grid_line(char *line, t_map *map, int i, size_t line_len)
{
	if (line_len > 0 && line[line_len - 1] == '\n')
	{
		line[line_len - 1] = '\0';
		line_len--;
	}
	if (line_len != (size_t)map->width)
	{
		free(line);
		throw_error("Map is not rectangular");
	}
	map->grid[i] = ft_strdup(line);
	free(line);
}

void	fill_map_grid(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL && i < map->height)
	{
		process_grid_line(line, map, i, ft_strlen(line));
		i++;
		line = get_next_line(fd);
	}
	close(fd);
}
