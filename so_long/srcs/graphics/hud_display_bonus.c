/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_display_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 00:19:17 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/10 02:47:43 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	render_hud_background_bonus(t_game *game)
{
	int	x;
	int	y;
	int	hud_width;

	hud_width = 100;
	y = 0;
	while (y < 60)
	{
		x = 0;
		while (x < hud_width)
		{
			mlx_pixel_put(game->mlx, game->window, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	render_moves_counter_bonus(t_game *game)
{
	char	*moves_str;
	char	*display_text;
	char	*temp;

	moves_str = ft_itoa(game->moves);
	if (!moves_str)
		return ;
	temp = ft_strjoin("Moves: ", moves_str);
	free(moves_str);
	if (!temp)
		return ;
	display_text = temp;
	mlx_string_put(game->mlx, game->window, 15, 25, 0xFFFFFF, display_text);
	free(display_text);
}

void	render_collectibles_counter_bonus(t_game *game)
{
	char	*collectibles_str;
	char	*display_text;
	char	*temp;

	collectibles_str = ft_itoa(game->map->collectibles);
	if (!collectibles_str)
		return ;
	temp = ft_strjoin("Items left: ", collectibles_str);
	free(collectibles_str);
	if (!temp)
		return ;
	display_text = temp;
	mlx_string_put(game->mlx, game->window, 15, 45, 0xFFFFFF, display_text);
	free(display_text);
}

void	render_game_status_bonus(t_game *game)
{
	if (game->game_over)
	{
		if (game->map->collectibles == 0)
			mlx_string_put(game->mlx, game->window,
				15, 85, 0x00FF00, "YOU WIN!");
		else
			mlx_string_put(game->mlx, game->window,
				15, 85, 0xFF0000, "GAME OVER!");
	}
}

void	render_full_hud(t_game *game)
{
	if (!game || !game->mlx || !game->window)
		return ;
	render_hud_background_bonus(game);
	render_moves_counter_bonus(game);
	render_collectibles_counter_bonus(game);
	render_game_status_bonus(game);
}
