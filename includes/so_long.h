/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:28:50 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/03 01:01:41 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "log.h"
# include "libft.h"
# include "mlx.h"

/*--- CONSTANTS ---*/

# define WIN_HEIGHT 960
# define WIN_WIDTH 1440

/*--- STRUCTS ---*/

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_map
{
	int		fd;
	char	**arr;
	short	error;
	size_t	height;
	size_t	width;
}	t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win;
	int		error;
	t_map	map;
}	t_game;

/*--- VALIDATE ---*/
// If you can't tell what this does by its name,
// I honestly can't help you...
int		validate_args_get_map_fd(int c, char *v[]);

/*--- INIT ---*/
void	init_game(int argc, char **argv, t_game *game);

/*--- WRAPPERS & UTILS ---*/
// Wrapper-function for `exit(2)` with custom functionality.
// @param msg: What you want to output to `STD{OUT/ERR}`
// @param exit_code: Self-explanatory. Note that
// any error-code other than `EXIT_SUCCESS` will be considered
// an error, and the message will be displayed in red.
void	wexit(const char *msg, int exit_code);
void	free_chr2d(char **arr);
char	**dstr_realloc2d(char **ptr, size_t nmemb);
#endif // !SO_LONG_H
