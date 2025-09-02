/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:44:50 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/02 16:46:44 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		handle_keypress(int keycode, t_game *game);
void	move_player(t_game *game, int dx, int dy);
int		is_valid_move(t_game *game, int x, int y);