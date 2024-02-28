/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassop <yassop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 13:31:00 by yben-yag          #+#    #+#             */
/*   Updated: 2024/02/26 10:05:29 by yassop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/includes/ft_printf.h"
# include "../Libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# ifdef __linux__
#  define OS "linux"
#  define LETTER_KEY_LEFT 97
#  define LETTER_KEY_RIGHT 100
#  define LETTER_KEY_UP 119
#  define LETTER_KEY_DOWN 115
#  define LETTER_KEY_ACTION 113
#  define ARROW_KEY_LEFT 65361
#  define ARROW_KEY_RIGHT 65363
#  define ARROW_KEY_UP 65362
#  define ARROW_KEY_DOWN 65364
#  define SPACE_BAR 32
#  define KEY_ESC 65307
# endif

# define WINDOW_TITLE "so_long"
# define WINDOW_WIDTH 2560
# define WINDOW_HEIGHT 1600
# define NB_LIFE 7
# define HUD_LM 920

typedef struct s_map
{
	int		height;
	int		width;
	char	**map;
}			t_map;

typedef struct s_count
{
	int		countp;
	int		counte;
	int		countc;
	int		countm;
}			t_count;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
}			t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	void	*mlx;
	void	*mlx_win;
	void	*win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
	t_map	*map;
}			t_data;

typedef struct s_sprite
{
}			t_sprite;

void		count_c_in_map(char **map, t_count *count);
void		count_m_in_map(char **map, t_count *count);
int			check_file_extension(char *filename, char *extension);
int			is_wall_line(char *line);
int			is_wall_enclosed_line(char *line);
int			check_pec(char *map_path);
int			init_map_lines(t_map *map, int height, int width);
t_map		*create_map(int height, int width);
void		free_map_structure(t_map **map);
int			validate_game_map(t_map *map, const char *map_path);
int			load_map_from_file(t_map *map, const char *filename);
int			validate_map_walls_and_size(t_map *map);
int			flood_fill(char **map, int x, int y, int *visited, int width,
				int height, int *collectibles_count, int *monsters_count);
int			close_window(t_data *vars);
int			get_map_dimensions(const char *map_path, int *height, int *width);
void		count_elements_in_map(char **map, t_count *count);
int			validate_counts(t_count count);

#endif
