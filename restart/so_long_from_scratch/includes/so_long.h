/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:22:46 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/03 00:07:01 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../libft/libft.h"
# include "../../libft/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

//Parse map structures
typedef struct s_position
{
	int		x;
	int		y;
} t_position;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	int			collectibles;
	int			exits;
	int			players;
	t_position	player_pos;
	t_position	exit_pos;
} t_map;

//Central functions:
t_map	parse_map(char *filename);
void	print_map_info(t_map *map);

// Utils
void	throw_error(char *message);

#endif