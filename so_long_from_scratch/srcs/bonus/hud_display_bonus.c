/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_display_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 00:19:17 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/10 01:28:39 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	render_hud_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < 40)
	{
		x = 0;
		while (x < 200)
		{
			mlx_pixel_put(game->mlx, game->window, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	render_moves_counter(t_game *game)
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
	render_hud_background(game);
	mlx_string_put(game->mlx, game->window, 10, 20, 0xFFFFFF, display_text);
	free(display_text);
}

void	render_collectibles_counter(t_game *game)
{
	char	*collectibles_str;
	char	*display_text;
	char	*temp;

	collectibles_str = ft_itoa(game->map->collectibles);
	if (!collectibles_str)
		return ;
	temp = ft_strjoin("Items: ", collectibles_str);
	free(collectibles_str);
	if (!temp)
		return ;
	display_text = temp;
	mlx_string_put(game->mlx, game->window, 10, 35, 0xFFFFFF, display_text);
	free(display_text);
}

void	render_full_hud(t_game *game)
{
	if (!game || !game->mlx || !game->window)
		return ;
	render_hud_background(game);
	render_moves_counter(game);
	render_collectibles_counter(game);
}
