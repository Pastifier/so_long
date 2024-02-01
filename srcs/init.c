/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:07:03 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/01 06:31:21 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static inline t_map	init_map(const char *file)
// {
// 	// !!IF ANY ERROR OCCURS, SET t_map.error TO THE APPROPRIATE ERROR-CODE!!

// 	// Check whether the file extension is valid. Exit accordingly.
// 	if (!check_map_extension(v[1]))
// 		wexit(INVALID_EXTENSION, EXIT_FAILURE);

// 	// Check whether the map, itself, is valid. Exit accordingly.
// 	// Create the map as you're checking(?)

// }
int	close_boi(t_game *game);

void	init_game(int argc, char **argv, t_game *game)
{
	game->map.fd = validate_args_get_map_fd(argc, argv);
	game->mlx_ptr = mlx_init();
	game->window = mlx_new_window(game->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "so_long");
	mlx_hook(game->window, 17, 0, close_boi, game);
}
