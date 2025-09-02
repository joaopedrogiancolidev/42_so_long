/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:35:47 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/02 17:33:39 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../../includes/so_long.h";

// t_map	parse_map(char *filename);
// int		validate_map(t_map *map);
// int		is_map_rectangular(t_map *map);
// int		is_map_closed(t_map *map);
// int		has_valid_path(t_map *map);


#include "../../includes/so_long.h"

t_map parse_map(char *filename)
{
    t_map map;
    
    // Remova as variáveis não utilizadas ou comente elas
    // int fd;          // REMOVER ou comentar
    // char *line;      // REMOVER ou comentar
    
    (void)filename; // Isso evita o warning de parâmetro não usado
    
    // Implementação placeholder básica
    map.width = 5;
    map.height = 5;
    map.collectibles = 1;
    map.exits = 1;
    map.players = 1;
    map.player_pos.x = 1;
    map.player_pos.y = 1;
    map.exit_pos.x = 3;
    map.exit_pos.y = 3;
    map.grid = NULL;
    
    return map;
}

int validate_map(t_map *map)
{
    (void)map; // Evita warning
    return 1; // Placeholder - sempre válido por enquanto
}

int is_map_rectangular(t_map *map)
{
    (void)map;
    return 1;
}

int is_map_closed(t_map *map)
{
    (void)map;
    return 1;
}

int has_valid_path(t_map *map)
{
    (void)map;
    return 1;
}
