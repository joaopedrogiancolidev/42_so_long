/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:25:09 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/09 20:41:41 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	init_graphics(t_game *game, t_map *map)
{
	game->map = map;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->window = mlx_new_window(game->mlx,
			map->width * TILE_SIZE,
			map->height * TILE_SIZE,
			"So_long project");
	ft_printf("🎨 Window Openned!\n");
	return (1);
}
