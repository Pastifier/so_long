/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 09:03:56 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/06 11:15:34 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//TODO:
// Test this function.
// 
// Returns true if the map file-extension is valid
// @param file: The provided file
static void	check_map_extension(const char *file);
static bool	check_valid_field_char(char c);

// Implement a function that checks for a valid map-layout.
bool	check_map_line_layout(char **lines, t_vector point, bool at_last)
{
	if (!lines[point.y])
		return (false);
	if ((point.y == 0 || (lines[point.y] + 1) == NULL)
		&& lines[point.y][point.x] == '1')
		return (true);
	else if ((lines[point.y][0] != '1'
		|| (at_last && lines[point.y][point.x] != '1')))
		return (false);
	else if (point.x != 0 && !at_last
		&& !check_valid_field_char(lines[point.y][point.x]))
		return (false);
	return (true);
}

int	validate_args_get_map_fd(int c, char *v[])
{
	int	map_fd;

	if (c != 2)
		wexit(ERR"Please provide a map!", EXIT_FAILURE);
	if (c > 2)
		wexit(ERR"Only accepting one argument.", EXIT_FAILURE);
	check_map_extension(v[1]);
	map_fd = open(v[1], O_RDONLY);
	if (map_fd == -1)
		wexit(ERR"Couldn't open file.", EXIT_FAILURE);
	return (map_fd);
}

void	check_map_extension(const char *file)
{
	char	*dot_addr;
	char	*nlt_addr;

	dot_addr = ft_strrchr(file, '.');
	if (!dot_addr)
		wexit(ERR"No extension specified. "INVALID_EXTENSION, EXIT_FAILURE);
	nlt_addr = ft_strchr(dot_addr, 0);
	if (ft_strncmp(".ber", dot_addr, (size_t)(nlt_addr - dot_addr + 1)))
		wexit(ERR"Wrong extension. "INVALID_EXTENSION, EXIT_FAILURE);
}

bool	check_valid_field_char(char c)
{
	return (c == '0' || c == 'P' || c == 'E');
}
