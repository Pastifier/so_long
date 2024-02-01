/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:26:09 by ebinjama          #+#    #+#             */
/*   Updated: 2024/01/26 23:26:09 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_boi(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->window);
	free(game->mlx_ptr);
	if (game->error)
		return (game->error);
	return (wexit("See you next time!", EXIT_SUCCESS), EXIT_SUCCESS);
}

int	main(int c, char *v[])
{
	static t_game	game;

	init_game(c, v, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
