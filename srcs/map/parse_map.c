/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:35:47 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/02 18:15:39 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <fcntl.h>

// Função para contar as linhas do mapa (altura)
static int get_map_height(char *filename)
{
    int fd;
    int height;
    char *line;
    
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        throw_error("Failed to open map file");
    
    height = 0;
    line = get_next_line(fd);
    while (line != NULL)
    {
        height++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (height);
}

// Função para ler o arquivo e preencher o grid
static void read_map_file(t_map *map, char *filename)
{
    int fd;
    int i;
    char *line;
    
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        throw_error("Failed to open map file");
    
    i = 0;
    line = get_next_line(fd);
    while (line != NULL)
    {
        // Remove a quebra de linha no final
        if (line[ft_strlen(line) - 1] == '\n')
            line[ft_strlen(line) - 1] = '\0';
        
        map->grid[i] = ft_strdup(line);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    close(fd);
}

// Função principal de parsing do mapa
t_map parse_map(char *filename)
{
    t_map map;
    int i;
    
    // Inicializa a estrutura com zeros
    map = (t_map){0};
    map.height = get_map_height(filename);
    
    if (map.height <= 0)
        throw_error("Map file is empty");
    
    // Aloca memória para o grid
    map.grid = malloc(sizeof(char *) * (map.height + 1));
    if (!map.grid)
        throw_error("Memory allocation failed for map grid");
    
    // Lê o arquivo para o grid
    read_map_file(&map, filename);
    map.grid[map.height] = NULL;
    
    // Define a largura baseada na primeira linha
    if (map.height > 0 && map.grid[0])
        map.width = ft_strlen(map.grid[0]);
    else
        throw_error("Invalid map format");
    
    // Conta os elementos do mapa e encontra posições
    i = 0;
    while (map.grid[i])
    {
        map.collectibles += count_char(map.grid[i], 'C');
        map.exits += count_char(map.grid[i], 'E');
        map.players += count_char(map.grid[i], 'P');
        find_positions(&map, map.grid[i], i);
        i++;
    }
    
    return (map);
}
