/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:31:11 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/02 18:09:43 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int count_char(char *str, char c)
{
    int count;
    int i;
    
    count = 0;
    i = -1;
    while (str[++i])
    {
        if (str[i] == c)
            count++;
    }
    return (count);
}

void find_positions(t_map *map, char *line, int row)
{
    int i;
    
    i = -1;
    while (line[++i])
    {
        if (line[i] == 'P')
        {
            map->player_pos.x = i;
            map->player_pos.y = row;
        }
        else if (line[i] == 'E')
        {
            map->exit_pos.x = i;
            map->exit_pos.y = row;
        }
    }
}
