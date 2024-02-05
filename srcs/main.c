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

int	main(int c, char *v[])
{
	static t_game	game;

	init_game(c, v, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
