/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:25:09 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/05 18:39:48 by jgiancol         ###   ########.fr       */
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
			map->width * 64,
			map->height * 64,
			"So_long project");
	ft_printf("🎨 Graphics initialized!\n");
	return (1);
}
