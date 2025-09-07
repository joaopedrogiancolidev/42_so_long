/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 20:53:16 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/06 20:53:31 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	test_textures(t_game *game)
{
	ft_printf("🧪 Testing texture rendering...\n");
	
	// Teste UMA textura de cada vez
	if (mlx_put_image_to_window(game->mlx, game->window, 
		game->textures.floor, 0, 0) == 0)
	{
		ft_printf("❌ mlx_put_image_to_window FAILED immediately!\n");
		return;
	}
	ft_printf("✅ Floor texture rendered successfully!\n");
	
	// Adicone um pequeno delay para ver
	sleep(1);
}