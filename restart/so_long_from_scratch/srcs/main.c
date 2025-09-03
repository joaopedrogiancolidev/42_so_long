/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:06:15 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/03 16:21:32 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
    t_map map;

    if (argc != 2)
    {
        ft_printf("Usage: %s <map_file.ber>\n", argv[0]);
        return (1);
    }

     ft_printf("🍳 Inicializing So Long...\n");

     map = parse_map(argv[1]);
     print_map_info(&map);

     ft_printf("🏁Map loaded sucessfully! \n");
     return (0);
}