/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:14:57 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/09 15:54:18 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	is_valid_move(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map->width || y < 0 || y >= game->map->height)
		return (0);
	if (game->map->grid[y][x] == '1')
		return (0);
	if (game->map->grid[y][x] == 'M')
	{
		ft_printf("💀 Game Over! Você foi pego por um inimigo!\n");
		game->game_over = 1;
		return (0);
	}
	if (game->map->grid[y][x] == 'E' && game->map->collectibles > 0)
	{
		ft_printf("🚪 Você precisa coletar todos os itens antes de sair! (%d restantes)\n", 
			game->map->collectibles);
		return (0);
	}
	return (1);
}

void	collect_item(t_game *game, int x, int y)
{
	if (game->map->grid[y][x] == 'C')
	{
		game->map->grid[y][x] = '0';
		game->collected++;
		game->map->collectibles--;
		ft_printf("🎯 Collectible coletado! (%d restantes)\n", game->map->collectibles);
		game->needs_rerender = 1;
	}
}

void	display_move_count(t_game *game)
{
	ft_printf("🚶 Movimentos: %d | Collectibles: %d\n", 
		game->moves, game->map->collectibles);
}

void	check_win_condition(t_game *game)
{
	if (game->map->grid[game->map->player_pos.y][game->map->player_pos.x] == 'E' 
		&& game->map->collectibles == 0)
	{
		ft_printf("🏆 PARABÉNS! Você venceu em %d movimentos!\n", game->moves);
		game->game_over = 1;
		close_game(game);
	}
}

void	move_player(t_game *game, int new_x, int new_y)
{
	int	old_x;
	int	old_y;

	if (game->map->grid[new_y][new_x] == 'M')
	{
		ft_printf("💀 Game Over! Você andou para cima de um inimigo!\n");
		game->game_over = 1;
		close_game(game);
		return;
	}
	
	if (!is_valid_move(game, new_x, new_y) || game->game_over)
		return;
	
	old_x = game->map->player_pos.x;
	old_y = game->map->player_pos.y;
	
	collect_item(game, new_x, new_y);
	
	game->map->grid[old_y][old_x] = '0';
	game->map->player_pos.x = new_x;
	game->map->player_pos.y = new_y;
	
	if (new_x != game->map->exit_pos.x || new_y != game->map->exit_pos.y)
		game->map->grid[new_y][new_x] = 'P';
	
	game->moves++;
	game->needs_rerender = 1;
	
	display_move_count(game);
	check_win_condition(game);
}

int	key_press(int keycode, t_game *game)
{
	int	new_x = game->map->player_pos.x;
	int	new_y = game->map->player_pos.y;
	
	printf("DEBUG: Tecla pressionada: %d\n", keycode);
	printf("DEBUG: Direção ANTES: %d\n", game->player_direction);
	
	if (game->game_over && keycode == ESC_KEY)
		close_game(game);
	if (game->game_over)
		return (0);
	
	if (keycode == ESC_KEY)
		close_game(game);
	else if (keycode == W_KEY || keycode == UP_KEY)
	{
		new_y--;
		game->player_direction = UP;
		printf("DEBUG: Apertou W/UP - Direction DEPOIS: %d\n", game->player_direction);
	}
	else if (keycode == S_KEY || keycode == DOWN_KEY)
	{
		new_y++;
		game->player_direction = DOWN;
		printf("DEBUG: Apertou S/DOWN - Direction DEPOIS: %d\n", game->player_direction);
	}
	else if (keycode == A_KEY || keycode == LEFT_KEY)
	{
		new_x--;
		game->player_direction = LEFT;
		printf("DEBUG: Apertou A/LEFT - Direction DEPOIS: %d\n", game->player_direction);
	}
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
	{
		new_x++;
		game->player_direction = RIGHT;
		printf("DEBUG: Apertou D/RIGHT - Direction DEPOIS: %d\n", game->player_direction);
	}
	else
	{
		printf("DEBUG: Tecla não reconhecida: %d\n", keycode);
		return (0);
	}
	
	printf("DEBUG: Direção FINAL antes de mover: %d\n", game->player_direction);
	
	if (new_x != game->map->player_pos.x || new_y != game->map->player_pos.y)
		move_player(game, new_x, new_y);
	else
		game->needs_rerender = 1;
		
	return (0);
}
