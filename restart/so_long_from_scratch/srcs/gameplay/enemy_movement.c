/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:34:44 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/08 00:51:03 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Inicializa os inimigos com direções baseadas na posição
void	init_enemies(t_game *game)
{
	int		y;
	int		x;
	int		enemy_count;

	ft_printf("🔍 DEBUG: Iniciando init_enemies...\n");
	
	if (!game || !game->map)
	{
		ft_printf("❌ ERROR: game ou map é NULL\n");
		return;
	}

	if (game->map->enemies == 0)
	{
		ft_printf("⚠️  Nenhum inimigo encontrado no mapa\n");
		game->map->enemies_data = NULL;
		return;
	}

	ft_printf("🤖 Encontrados %d inimigos no mapa\n", game->map->enemies);

	// Aloca array de dados dos inimigos
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
				
				// ✅ DEBUG CRÍTICO - MOSTRA CADA INIMIGO
				ft_printf("🎯 Inimigo %d encontrado em (%d,%d) - ", 
					enemy_count, x, y);
				
				// FORÇA: primeiro horizontal, segundo vertical, terceiro horizontal, etc.
				if (enemy_count % 2 == 0) // Inimigos PARES: Horizontal
				{
					game->map->enemies_data[enemy_count].movement_type = 0;
					game->map->enemies_data[enemy_count].direction = 0;
					game->map->enemies_data[enemy_count].last_horizontal_direction = 0;
					ft_printf("HORIZONTAL →\n");
				}
				else // Inimigos ÍMPARES: Vertical
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
	ft_printf("✅ %d inimigos inicializados com padrões de movimento\n", enemy_count);
}

// Verifica se o inimigo pode se mover para uma posição
int	can_enemy_move(t_game *game, int x, int y)
{
	// Verifica limites do mapa
	if (x < 0 || x >= game->map->width || y < 0 || y >= game->map->height)
	{
		ft_printf("🚫 Movimento bloqueado: fora dos limites (%d,%d)\n", x, y);
		return (0);
	}
	
	// Verifica se não é parede
	if (game->map->grid[y][x] == '1')
	{
		ft_printf("🧱 Movimento bloqueado: parede em (%d,%d)\n", x, y);
		return (0);
	}
	
	// Verifica se não tem outro inimigo
	if (game->map->grid[y][x] == 'M')
	{
		ft_printf("👥 Movimento bloqueado: outro inimigo em (%d,%d)\n", x, y);
		return (0);
	}
	
	ft_printf("✅ Movimento permitido para (%d,%d)\n", x, y);
	return (1);
}

// Move um inimigo específico
void	move_single_enemy(t_game *game, int enemy_index)
{
	t_enemy	*enemy;
	int		new_x;
	int		new_y;
	int		old_x;
	int		old_y;

	if (enemy_index >= game->map->enemies)
	{
		ft_printf("❌ Índice de inimigo inválido: %d\n", enemy_index);
		return;
	}

	enemy = &game->map->enemies_data[enemy_index];
	old_x = enemy->pos.x;
	old_y = enemy->pos.y;
	new_x = old_x;
	new_y = old_y;

	ft_printf("🤖 Movendo inimigo %d de (%d,%d), tipo=%d, dir=%d\n", 
		enemy_index, old_x, old_y, enemy->movement_type, enemy->direction);

    ft_printf("🤖 Inimigo %d - Tipo: %s, Direção: %d\n", 
    enemy_index,
    (enemy->movement_type == 0) ? "HORIZONTAL" : "VERTICAL",
    enemy->direction);
	// Calcula nova posição baseada na direção
	if (enemy->movement_type == 0) // Horizontal
	{
		if (enemy->direction == 0) // Direita
			new_x++;
		else // Esquerda
			new_x--;
	}
	else // Vertical
	{
		if (enemy->direction == 2) // Baixo
			new_y++;
		else // Cima
			new_y--;
	}

	ft_printf("🎯 Nova posição calculada: (%d,%d)\n", new_x, new_y);

	// Verifica se pode se mover
	if (can_enemy_move(game, new_x, new_y))
	{
		// Move o inimigo
		game->map->grid[old_y][old_x] = '0'; // Remove da posição antiga
		game->map->grid[new_y][new_x] = 'M'; // Coloca na nova posição
		enemy->pos.x = new_x;
		enemy->pos.y = new_y;
		ft_printf("✅ Inimigo %d movido para (%d,%d)\n", enemy_index, new_x, new_y);
	}
	else
	{
		// Inverte direção quando bate em obstáculo
		if (enemy->movement_type == 0) // Horizontal
		{
			enemy->direction = (enemy->direction == 0) ? 1 : 0; // Troca direita/esquerda
			ft_printf("🔄 Inimigo %d inverteu direção horizontal: %d\n", enemy_index, enemy->direction);
		}
		else // Vertical
		{
			enemy->direction = (enemy->direction == 2) ? 3 : 2; // Troca baixo/cima
			ft_printf("🔄 Inimigo %d inverteu direção vertical: %d\n", enemy_index, enemy->direction);
		}
	}
	if (can_enemy_move(game, new_x, new_y))
	{
		// Move o inimigo
		game->map->grid[old_y][old_x] = '0';
		game->map->grid[new_y][new_x] = 'M';
		enemy->pos.x = new_x;
		enemy->pos.y = new_y;
		
		// Adicione esta linha:
		update_enemy_sprite_on_movement(enemy);
		
		ft_printf("✅ Inimigo %d movido para (%d,%d)\n", enemy_index, new_x, new_y);
}
}

// Verifica colisão entre player e inimigos
void	check_player_collision(t_game *game)
{
	int	i;

	if (!game->map->enemies_data)
		return;

	i = 0;
	while (i < game->map->enemies)
	{
		if (game->map->enemies_data[i].pos.x == game->map->player_pos.x &&
			game->map->enemies_data[i].pos.y == game->map->player_pos.y)
		{
			ft_printf("💀 Game Over! Você foi pego por um inimigo!\n");
			game->game_over = 1;
			close_game(game);
			return;
		}
		i++;
	}
}

// Move todos os inimigos
void	move_enemies(t_game *game)
{
	static int	enemy_move_counter = 0;
	int			i;

	// Debug: mostra contador a cada 10 frames
	// if (enemy_move_counter % 10 == 0)
	// 	ft_printf("⏱️  Enemy move counter: %d\n", enemy_move_counter);

	// Move inimigos mais devagar que a animação (a cada 60 frames)
	enemy_move_counter++;
	if (enemy_move_counter < 600)
		return;

	ft_printf("🚀 Movendo todos os inimigos! Frame: %d\n", enemy_move_counter);
	enemy_move_counter = 0;

	if (!game || !game->map)
	{
		ft_printf("❌ game ou map é NULL em move_enemies\n");
		return;
	}

	if (game->map->enemies == 0 || !game->map->enemies_data)
	{
		ft_printf("⚠️  Sem inimigos ou enemies_data é NULL\n");
		return;
	}

	i = 0;
	while (i < game->map->enemies)
	{
		move_single_enemy(game, i);
		i++;
	}

	// Verifica colisão após mover todos os inimigos
	check_player_collision(game);
	game->needs_rerender = 1;
	ft_printf("🎨 Renderização marcada como necessária\n");
}
