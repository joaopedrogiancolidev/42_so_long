/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 02:33:53 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/10 02:33:55 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "so_long.h"

void	render_hud_background(t_game *game);
void	render_moves_counter(t_game *game);
void	render_collectibles_counter(t_game *game);
void	render_full_hud(t_game *game);

#endif
