/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:35:47 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/02 16:41:04 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/so_long.h";

t_map	parse_map(char *filename);
int		validate_map(t_map *map);
int		is_map_rectangular(t_map *map);
int		is_map_closed(t_map *map);
int		has_valid_path(t_map *map);
