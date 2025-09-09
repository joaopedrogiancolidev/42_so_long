/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:34:44 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/09 19:41:07 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Inicializa os inimigos com direções baseadas na posição
void	init_enemies(t_game *game)
{
	int		y;
	int		x;
	int		enemy_count;

	if (!game || !game->map)
	{
		return ;
	}
	if (game->map->enemies == 0)
	{
		game->map->enemies_data = NULL;
		return ;
	}
	game->map->enemies_data = malloc(sizeof(t_enemy) * game->map->enemies);
	if (!game->map->enemies_data)
		throw_error("Falha ao alocar dados dos inimigos");
	enemy_count = 0;
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->grid[y][x] == 'M')
			{
				game->map->enemies_data[enemy_count].pos.x = x;
				game->map->enemies_data[enemy_count].pos.y = y;
				if (enemy_count % 2 == 0)
				{
					game->map->enemies_data[enemy_count].movement_type = 0;
					game->map->enemies_data[enemy_count].direction = 0;
					game->map->enemies_data[enemy_count].last_horizontal_direction = 0;
					ft_printf("HORIZONTAL →\n");
				}
				else
				{
					game->map->enemies_data[enemy_count].movement_type = 1;
					game->map->enemies_data[enemy_count].direction = 2;
					game->map->enemies_data[enemy_count].last_horizontal_direction = 0;
					ft_printf("VERTICAL ↓\n");
				}
				enemy_count++;
			}
			x++;
		}
		y++;
	}
}

int	can_enemy_move(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map->width || y < 0 || y >= game->map->height)
	{
		return (0);
	}
	if (game->map->grid[y][x] == '1')
	{
		return (0);
	}
	if (game->map->grid[y][x] == 'M')
	{
		return (0);
	}
	return (1);
}

void	move_single_enemy(t_game *game, int enemy_index)
{
	t_enemy	*enemy;
	int		new_x;
	int		new_y;
	int		old_x;
	int		old_y;

	if (enemy_index >= game->map->enemies)
	{
		return ;
	}
	enemy = &game->map->enemies_data[enemy_index];
	old_x = enemy->pos.x;
	old_y = enemy->pos.y;
	new_x = old_x;
	new_y = old_y;
	if (enemy->movement_type == 0)
	{
		if (enemy->direction == 0)
			new_x++;
		else
			new_x--;
	}
	else
	{
		if (enemy->direction == 2)
			new_y++;
		else
			new_y--;
	}
	if (can_enemy_move(game, new_x, new_y))
	{
		game->map->grid[old_y][old_x] = '0';
		game->map->grid[new_y][new_x] = 'M';
		enemy->pos.x = new_x;
		enemy->pos.y = new_y;
	}
	else
	{
		if (enemy->movement_type == 0)
		{
			enemy->direction = (enemy->direction == 0) ? 1 : 0;
			ft_printf("🔄 Inimigo %d inverteu direção horizontal: %d\n",
				enemy_index, enemy->direction);
		}
		else
		{
			enemy->direction = (enemy->direction == 2) ? 3 : 2;
			ft_printf("🔄 Inimigo %d inverteu direção vertical: %d\n",
				enemy_index, enemy->direction);
		}
	}
	if (can_enemy_move(game, new_x, new_y))
	{
		game->map->grid[old_y][old_x] = '0';
		game->map->grid[new_y][new_x] = 'M';
		enemy->pos.x = new_x;
		enemy->pos.y = new_y;
		update_enemy_sprite_on_movement(enemy);
	}
}

void	check_player_collision(t_game *game)
{
	int	i;

	if (!game->map->enemies_data)
		return ;
	i = 0;
	while (i < game->map->enemies)
	{
		if (game->map->enemies_data[i].pos.x == game->map->player_pos.x
			&& game->map->enemies_data[i].pos.y == game->map->player_pos.y)
		{
			ft_printf("💀 Game Over! Você foi pego por um inimigo!\n");
			game->game_over = 1;
			close_game(game);
			return ;
		}
		i++;
	}
}

void	move_enemies(t_game *game)
{
	static int	enemy_move_counter = 0;
	int			i;

	enemy_move_counter++;
	if (enemy_move_counter < 600)
		return ;
	enemy_move_counter = 0;
	if (!game || !game->map)
	{
		return ;
	}
	if (game->map->enemies == 0 || !game->map->enemies_data)
	{
		return ;
	}
	i = 0;
	while (i < game->map->enemies)
	{
		move_single_enemy(game, i);
		i++;
	}
	check_player_collision(game);
	game->needs_rerender = 1;
}
