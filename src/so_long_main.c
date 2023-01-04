/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:01:35 by hozdemir          #+#    #+#             */
/*   Updated: 2023/01/04 04:13:48 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ifmai.h"

static void	map(t_data *data, char *path)
{
	map_size(data, path);
	map_create(data, path);
	map_wall_check(data);
	temp_map_create(data, path);
	map_materials(data);
	data->collect.x_collectable = malloc(sizeof(int) * data->count_collectable);
	data->collect.y_collectable = malloc(sizeof(int) * data->count_collectable);
	setting_collect_indeks(data);
	materials_drop_check(data, data->player.x_player, data->player.y_player);
	materials_count_check(data);
}

static void	photo_in_program(t_data *data)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	data->wall_img = mlx_xpm_file_to_image(data->mlx, WALLXPM, &x, &y);
	data->collect.img = mlx_xpm_file_to_image(data->mlx, COLL, &x, &y);
	data->player.img = mlx_xpm_file_to_image(data->mlx, HEROXPM, &x, &y);
	data->exit_img = mlx_xpm_file_to_image(data->mlx, EXITXPM, &x, &y);
	data->zemin_img = mlx_xpm_file_to_image(data->mlx, ZEMINXPM, &x, &y);
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
	map_photo_parse(data, 0, 0);
	mlx_hook(data->win, 17, 0, close_all, data);
	mlx_hook(data->win, KEY, 1L << 0, key_hook, data);
	mlx_loop(data->mlx);
	return (0);
}
