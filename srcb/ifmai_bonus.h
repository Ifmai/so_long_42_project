/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifmai_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 03:57:02 by hozdemir          #+#    #+#             */
/*   Updated: 2023/01/04 18:02:07 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IFMAI_BONUS_H
# define IFMAI_BONUS_H

# include <fcntl.h>
# include "../ft_printf/src/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include "../mlx_lib/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "textures_bonus.h"

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
# define WHITE 0xFFFFFF

typedef struct s_enemy
{
	int		*x;
	int		*y;
	int		*check_wall;
	void	**img;
	void	**r_img;
	int		*fr;
}			t_enemy;

typedef struct s_material
{
	int			*x;
	int			*y;
	void		**img;
}				t_collect;

typedef struct s_player
{
	int			x_player;
	int			y_player;
	void		**b_img;
	void		**r_img;
	void		**l_img;
	void		**j_img;
	void		**d_img;
}				t_player;

typedef struct s_data
{
	t_collect	collect;
	void		*mlx;
	void		*win;
	char		**map;
	t_player	p;
	char		**temp_map;
	t_enemy		e;
	void		*wall_img;
	void		*exit_img;
	void		*floor;
	char		*steps;
	int			w_map;
	int			h_map;
	int			count_collectable;
	int			count_exit;
	int			count_player;
	int			count_enemy;
	int			temp_count_coll;
	int			temp_count_exit;
	int			step_count;
	int			rx;
	int			ry;
}				t_data;

size_t	so_strlen(char *str);
int		check_path(char *path);
void	clear_data(t_data *data);
void	update_step(t_data *d);
void	map_create(t_data *data, char *path);
void	temp_map_create(t_data *data, char *path);
void	map_size(t_data *data, char *path);
void	map_wall_check(t_data *data);
void	map_materials(t_data *data);
void	materials_count_check(t_data *data);
void	materials_drop_check(t_data *data, int x, int y);

void	setting_collect_indeks(t_data *data);
void	setting_enemy_indeks(t_data *d);
void	setting_player_indeks(t_data *d);
void	error_print(char *str);

void	add_player_photo(t_data *d, int *x, int *y);
void	add_player_jump(t_data *d, int *x, int *y);
void	add_dead_player(t_data *d, int *x, int *y);
void	add_enemy_photo(t_data *d, int *x, int *y);
void	add_coll_photo(t_data *d, int *x, int *y);

int		render_parse(t_data *data);
void	render_enemy(t_data *d, int *x, int *y);
void	render_collect(t_data *d, int *x, int *y);
void	key_render_parse(int keycode, t_data *d);
int		key_hook(int keycode, t_data *data);
void	loop_map_parse(int keycode, int *i, int *j, t_data *d);
void	dead_player(t_data *data);

#endif
