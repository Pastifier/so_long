/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:07:03 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/06 11:03:18 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void		validate_line_part1(t_gnl *line, char **self, size_t *prevlen);
static char		**check_while_loading(int fd, size_t *capacity, t_map *map);
static char		**load_map(int fd, t_map *map);
static t_map	init_map(int fd);

void	init_game(int argc, char **argv, t_game *game)
{
	game->map = init_map(validate_args_get_map_fd(argc, argv));
	if (game->map.error)
		wexit(ERR"Failed to load map.", EXIT_FAILURE);
	game->mlx_ptr = mlx_init();
	game->win = mlx_new_window(game->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "so_long");
	mlx_hook(game->win, ON_DESTROY, 0, clean_resources, game);
	mlx_hook(game->win, ON_KEYDOWN, 0, get_input, game);
}

t_map	init_map(int fd)
{
	t_map		self;
	t_vector	point;

	self = (t_map){0};
	self.arr = load_map(fd, &self);
	if (!self.arr)
		return (self.error = true, self);
	point.y = -1;
	 while (self.arr[++point.y])
	 {
	 	point.x = -1;
	 	while (self.arr[point.y][++point.x])
	 		if (!check_map_line_layout(self.arr,
	 				point, (!self.arr[point.y][point.x + 1])))
	 			return (free_chr2d(self.arr),
	 				wexit(ERR"INVALID MAP!", EXIT_FAILURE), self);
	 }
	return (self);
}

char	**load_map(int fd, t_map *map)
{
	char	**self;
	size_t	capacity;

	capacity = 4;
	self = check_while_loading(fd, &capacity, map);
	return (self);
}

char	**check_while_loading(int fd, size_t *capacity, t_map *map)
{
	t_gnl	line;
	size_t	i;
	size_t	prevlen;
	char	**self;

	self = ft_calloc(*capacity + 1, sizeof(*self));
	if (!self)
		return (wexit(ERR"Couldn't load map.", EXIT_FAILURE), NULL);
	line = get_next_line(fd);
	if (!line.line)
		return (free(self),
			wexit(ERR"The file seems to be empty.", EXIT_FAILURE), NULL);
	i = 0;
	while (line.line)
	{
		prevlen = line.len;
		self[i++] = line.line;
		if (i >= *capacity)
			self = dstr_realloc2d(self, (*capacity *= 2, *capacity));
		line = get_next_line(fd);
		validate_line_part1(&line, self, &prevlen);
	}
	map->height = i;
	map->width = line.len;
	return (self);
}

void	validate_line_part1(t_gnl *line, char **self, size_t *prevlen)
{
	if (!line)
		return ;
	if (line->error)
		return (free_chr2d(self),
			wexit(ERR "Couldn't read from file!", EXIT_FAILURE));
	if (line->line && line->len != *prevlen)
		return (free_chr2d(self), free(line->line),
			wexit(ERR "Map is not rectangular!", EXIT_FAILURE));
}
