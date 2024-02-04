/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:07:03 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/04 13:47:56 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int				close_boi(t_game *game);
static void		validate_line_part1(t_gnl *line, char **self, size_t *prevlen);
static char		**check_while_loading(int fd, size_t *capacity);
static char		**load_map(int fd);
static t_map	init_map(int fd);

void	init_game(int argc, char **argv, t_game *game)
{
	game->map = init_map(validate_args_get_map_fd(argc, argv));
	game->mlx_ptr = mlx_init();
	game->win = mlx_new_window(game->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "so_long");
	mlx_hook(game->win, 17, 0, close_boi, game);
}

t_map	init_map(int fd)
{
	t_map	self;
	int		i;

	self = (t_map){0};
	self.arr = load_map(fd);
	i = 0;
	while (i)
		;
	return (self);
}

char	**load_map(int fd)
{
	char	**self;
	size_t	capacity;

	capacity = 4;
	self = check_while_loading(fd, &capacity);
	return (self);
}

char	**check_while_loading(int fd, size_t *capacity)
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
		return (wexit(ERR"The file seems to be empty.", EXIT_FAILURE), NULL);
	i = 0;
	while (line.line)
	{
		prevlen = line.len;
		self[i++] = line.line;
		if (i >= *capacity)
		{
			self = dstr_realloc2d(self, (*capacity *= 2, *capacity));
			if (!self)
				return (wexit(ERR"Couldn't load map.", EXIT_FAILURE), NULL);
		}
		line = get_next_line(fd);
		validate_line_part1(&line, self, &prevlen);
	}
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
		return (free_chr2d(self),
			wexit(ERR "Map is not rectangular!", EXIT_FAILURE));
}
