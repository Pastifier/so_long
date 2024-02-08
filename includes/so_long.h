/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:28:50 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/08 11:08:56 by ebinjama         ###   ########.fr       */
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

# ifdef __linux__

enum e_keysyms
{
	KEY_SPACE = 32,
	KEY_ESC = 0xFF1B,
	KEY_LEFT = 65361,
	KEY_UP,
	KEY_RIGHT,
	KEY_DOWN
};
# endif // !__linux__

# ifdef __MACH__

enum e_keysyms
{
	KEY_SPACE = 49,
	KEY_ESC = 53,
	KEY_LEFT = 123,
	KEY_RIGHT,
	KEY_DOWN,
	KEY_UP
};
# endif // !__MACH__

enum e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP,
	ON_MOUSEDOWN,
	ON_MOUSEUP,
	ON_MOUSEMOVE,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

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
	bool	error;
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
bool	check_map_line_layout(char **lines, t_vector point, bool at_last);
int		get_input(int keycode, t_game *game);
int		clean_resources(t_game *game);
#endif // !SO_LONG_H
