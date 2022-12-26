/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifmai_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 03:57:02 by hozdemir          #+#    #+#             */
/*   Updated: 2022/12/26 17:32:29 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IFMAI_H
# define IFMAI_H

# include <fcntl.h>
# include "./ft_printf/src/ft_printf.h"
# include "./ft_printf/libft/libft.h"
# include "./mlx_lib/mlx.h"
# include "./get_next_line/get_next_line.h"
# include "textures.h"


# define PATHERR "ERROR MAP FİLE"
# define WALLERR  "BRO DUVAR HATALI AÇIK VAR"
# define PLAYERERR "BRO SADECE 1 OYUNCU OLABİLİR"
# define EXITERR "EXIT ERRORS"
# define COLLERR "BRO 1 TANE MEYVE YOK AMK NE YİYEK AÇMI KALAK"
# define MAPERR "BRO MAP HATALI"
# define MAPVER "BRO YANLIŞ HARFLER VAR MAPTE"

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

typedef struct s_enemy
{
	int		*x;
	int		*y;
	void	**img;
}			t_enemy;

typedef struct s_material
{
	int			*x;
	int			*y;
	void		*img;
}				t_collect;

typedef struct s_player
{
	int			x_player;
	int			y_player;
	void		**b_img;
	void		**r_img;
	void		**l_img;
	void		**j_img;
}				t_player;

typedef struct s_data
{
	t_collect	collect;
	void		*mlx;
	void		*win;
	char		**map;
	t_player	p;
	t_enemy		e;
	char		**temp_map;
	void		*wall_img;
	void		*exit_img;
	void		*zemin_img;
	int			w_map;
	int			h_map;
	int			count_collectable;
	int			count_exit;
	int			count_player;
	int			count_enemy;
	int			temp_count_coll;
	int			temp_count_exit;
	int			step_count;
}				t_data;

int		check_path(char *path);
void	clear_data(t_data *data);

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
void	add_enemy_photo(t_data *d, int *x, int *y);

int		render_parse(t_data *data);
void	key_render_parse(int keycode, t_data *d);
int		key_hook(int keycode, t_data *data);

#endif
