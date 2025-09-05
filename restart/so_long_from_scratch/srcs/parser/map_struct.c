/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:39:27 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/05 14:07:43 by jgiancol         ###   ########.fr       */
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

t_map	init_map_struct(void)
{
	t_map	map;

	map.grid = NULL;
	map.width = 0;
	map.height = 0;
	map.collectibles = 0;
	map.exits = 0;
	map.players = 0;
	map.player_pos.x = 0;
	map.player_pos.y = 0;
	map.exit_pos.x = 0;
	map.exit_pos.y = 0;
	return (map);
}
