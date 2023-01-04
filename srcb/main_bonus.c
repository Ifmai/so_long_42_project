/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:01:35 by hozdemir          #+#    #+#             */
/*   Updated: 2023/01/04 18:54:30 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ifmai_bonus.h"

static int	close_all(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

static void	map(t_data *data, char *path)
{
	map_size(data, path);
	map_create(data, path);
	map_wall_check(data);
	temp_map_create(data, path);
	map_materials(data);
	data->collect.x = malloc(sizeof(int) * data->count_collectable);
	data->collect.y = malloc(sizeof(int) * data->count_collectable);
	data->e.x = malloc(sizeof(int) * data->count_enemy);
	data->e.y = malloc(sizeof(int) * data->count_enemy);
	data->e.check_wall = malloc(sizeof(int) * data->count_enemy);
	setting_collect_indeks(data);
	setting_player_indeks(data);
	setting_enemy_indeks(data);
	materials_drop_check(data, data->p.x_player, data->p.y_player);
	materials_count_check(data);
}

static void	clear_fr(int *fr, int *check_wall, t_data *d)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		fr[i] = 0;
		i++;
	}
	i = 0;
	while (i < d->count_enemy)
	{
		check_wall[i] = 0;
		i++;
	}
}

static void	photo_in_program(t_data *data)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	data->wall_img = mlx_xpm_file_to_image(data->mlx, WALLXPM, &x, &y);
	data->exit_img = mlx_xpm_file_to_image(data->mlx, EXITXPM, &x, &y);
	data->floor = mlx_xpm_file_to_image(data->mlx, ZEMINXPM, &x, &y);
	data->collect.img = malloc(sizeof(void *) * 16);
	data->p.b_img = malloc(sizeof(void *) * 4);
	data->p.l_img = malloc(sizeof(void *) * 8);
	data->p.r_img = malloc(sizeof(void *) * 8);
	data->p.j_img = malloc(sizeof(void *) * 8);
	data->p.d_img = malloc(sizeof(void *) * 7);
	data->e.img = malloc(sizeof(void *) * 8);
	data->e.r_img = malloc(sizeof(void *) * 8);
	data->e.fr = malloc(sizeof(int) * 7);
	clear_fr(data->e.fr, data->e.check_wall, data);
	add_player_photo(data, &x, &y);
	add_player_jump(data, &x, &y);
	add_enemy_photo(data, &x, &y);
	add_dead_player(data, &x, &y);
	add_coll_photo(data, &x, &y);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (0);
	data = malloc(sizeof(t_data));
	if (check_path(av[1]))
		error_print(PATHERR);
	clear_data(data);
	map(data, av[1]);
	data->w_map *= 64;
	data->h_map *= 64;
	photo_in_program(data);
	data->win = mlx_new_window(data->mlx, data->w_map, data->h_map, "so long");
	mlx_loop_hook(data->mlx, render_parse, data);
	mlx_hook(data->win, KEY, 1L << 0, key_hook, data);
	mlx_hook(data->win, 17, 0, close_all, data);
	mlx_loop(data->mlx);
	return (0);
}
