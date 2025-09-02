/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:47:34 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/02 19:20:32 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void	throw_error(char *message);
// void	clean_exit(t_game *game, int exit_code);

#include "../../includes/so_long.h"
#include <string.h>  // ← ADICIONE ESTA LINHA

void throw_error(char *message)
{
    write(2, "Error\n", 6);
    write(2, message, strlen(message));
    write(2, "\n", 1);
    exit(EXIT_FAILURE);
}

void clean_exit(t_game *game, int exit_code)
{
    (void)game;  // ← ADICIONE ESTA LINHA para evitar warning
    // Implementação placeholder para cleanup
    exit(exit_code);
}