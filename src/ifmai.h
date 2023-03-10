/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifmai.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 03:57:02 by hozdemir          #+#    #+#             */
/*   Updated: 2023/01/04 18:02:28 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IFMAI_H
# define IFMAI_H

# include <fcntl.h>
# include "../ft_printf/src/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include "../mlx_lib/mlx.h"
# include "../get_next_line/get_next_line.h"

# define WALLXPM "./textures/wall.xpm"
# define COLL "./textures/goldenapple.xpm"
# define EXITXPM "./textures/exit.xpm"
# define HEROXPM "./textures/hero.xpm"
# define ZEMINXPM "./textures/ground.xpm"

# define PATHERR "ERROR MAP FİLE. x.ber"
# define WALLERR  "ERROR. Map not surrounded by a wall."
# define PLAYERERR "ERROR. Only one player."
# define EXITERR "EXIT ERROR."
# define COLLERR "ERROR. Min 1 collectable."
# define MAPERR "ERROR. Map is wrong."
# define MAPVER "ERROR. There are invalid letters."

# define KEY 2
# define W	13
# define S	1
# define A	0
# define D	2
# define UP	126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define ESC 53

typedef struct s_material
{
	int			*x_collectable;
	int			*y_collectable;
	void		*img;
}				t_collect;

typedef struct s_player
{
	int			x_player;
	int			y_player;
	void		*img;
}				t_player;

typedef struct s_data
{
	t_collect	collect;
	void		*mlx;
	void		*win;
	char		**map;
	t_player	player;
	char		**temp_map;
	void		*wall_img;
	void		*exit_img;
	void		*zemin_img;
	int			w_map;
	int			h_map;
	int			count_collectable;
	int			count_exit;
	int			count_player;
	int			temp_count_coll;
	int			temp_count_exit;
	int			step_count;
}				t_data;

int		check_path(char *path);
void	clear_data(t_data *data);
int		close_all(t_data *data);
void	map_create(t_data *data, char *path);
void	temp_map_create(t_data *data, char *path);
void	map_size(t_data *data, char *path);
void	map_wall_check(t_data *data);
void	map_materials(t_data *data);
void	materials_count_check(t_data *data);
void	materials_drop_check(t_data *data, int x, int y);
void	setting_collect_indeks(t_data *data);
void	error_print(char *str);
void	map_photo_parse(t_data *data, int x, int y);
int		key_hook(int keycode, t_data *data);
size_t	so_strlen(char *str);

#endif
