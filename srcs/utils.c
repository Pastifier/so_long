/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:49:03 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/05 11:55:05 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_chr2d(char **arr)
{
	char	**original;

	if (!arr)
		return ;
	original = arr;
	while (*arr)
		free(*arr++);
	free(original);
}

char	**dstr_realloc2d(char **ptr, size_t nmemb)
{
	char	**self;
	size_t	i;

	i = -1;
	self = ft_calloc(nmemb, sizeof(*self));
	if (!self)
	{
		free_chr2d(ptr);
		wexit(ERR"Couldn't load resources...", EXIT_FAILURE);
		return (NULL);
	}
	while (ptr[++i])
		self[i] = ptr[i];
	free(ptr);
	return (self);
}

int	get_input(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		return (clean_resources(game));
	return (0);
}

int	clean_resources(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win);
	free(game->mlx_ptr);
	free_chr2d(game->map.arr);
	if (game->error)
		return (game->error);
	return (wexit("See you next time!", EXIT_SUCCESS), EXIT_SUCCESS);
}
