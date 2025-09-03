/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:31:15 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/03 16:18:17 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	throw_error(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

t_map parse_map(char *filename)
{
	t_map	map;
	int		fd;
	char	*line;
	int		i;
	size_t	line_len;

	map = (t_map){0};
	map.grid = NULL;
	map.height = 0;
	map.width = 0;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		throw_error("Cannot open map file");

	// First pass: count lines and determine width
	while ((line = get_next_line(fd)) != NULL)
	{
		if (map.height == 0 && ft_strlen(line) > 0)
		{
			map.width = ft_strlen(line);
			if (line[map.width - 1] == '\n')
				map.width--;
		}
		map.height++;
		free(line);
	}
	close(fd);
	
	if (map.height == 0 || map.width == 0)
		throw_error("Map is empty or invalid");
	
	// Allocate memory for grid
	map.grid = ft_calloc(map.height + 1, sizeof(char *));
	if (!map.grid)
		throw_error("Memory allocation failed");
	
	// Second pass: read map content
	fd = open(filename, O_RDONLY);
	i = 0;
	while ((line = get_next_line(fd)) != NULL && i < map.height)
	{
		line_len = ft_strlen(line);
		if (line_len > 0 && line[line_len - 1] == '\n')
		{
			line[line_len - 1] = '\0';
			line_len--;
		}
		
		// Validate line length - convert map.width to size_t for comparison
		if (line_len != (size_t)map.width)
		{
			free(line);
			throw_error("Map is not rectangular");
		}
		
		map.grid[i] = ft_strdup(line);
		free(line);
		i++;
	}
	close(fd);
	
	return (map);
}

void print_map_info(t_map *map)
{
    ft_printf("🗺️  Map Info:\n");
    ft_printf("   Size: %dx%d\n", map->width, map->height);
    ft_printf("   Collectibles: %d\n", map->collectibles);
    ft_printf("   Exits: %d\n", map->exits);
    ft_printf("   Players: %d\n", map->players);
    
    ft_printf("   Grid:\n");
    for (int y = 0; y < map->height; y++)
    {
        ft_printf("      %s\n", map->grid[y]);
    }
}
