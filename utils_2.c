/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:49:07 by hozdemir          #+#    #+#             */
/*   Updated: 2022/12/26 17:00:05 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ifmai.h"

void	map_photo_parse(t_data *d, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (d->map[++i])
	{
		x = 0;
		j = -1;
		while (d->map[i][++j])
		{
			if (d->map[i][j] != '1')
				mlx_put_image_to_window(d->mlx, d->win, d->zemin_img, x, y);
			if (d->map[i][j] == '1')
				mlx_put_image_to_window(d->mlx, d->win, d->wall_img, x, y);
			else if (d->map[i][j] == 'E')
				mlx_put_image_to_window(d->mlx, d->win, d->exit_img, x, y);
			else if (d->map[i][j] == 'C')
				mlx_put_image_to_window(d->mlx, d->win, d->collect.img, x, y);
			else if (d->map[i][j] == 'P')
				mlx_put_image_to_window(d->mlx, d->win, d->player.img, x, y);
			x += 64;
		}
		y += 64;
	}
}

void	materials_drop_check(t_data *d, int x, int y)
{
	if (d->temp_map[y][x] == 'C')
		d->temp_count_coll += 1;
	if (d->temp_map[y][x] == 'E')
		d->temp_count_exit += 1;
	d->temp_map[y][x] = '.';
	if (d->temp_map[y][x - 1] != '1' && d->temp_map[y][x - 1] != '.'
		&& d->temp_map[y][x - 1] != 'P' && d->temp_map[y][x - 1] != 'E')
		materials_drop_check(d, x - 1, y);
	if (d->temp_map[y + 1][x] != '1' && d->temp_map[y + 1][x] != '.'
		&& d->temp_map[y + 1][x] != 'P' && d->temp_map[y + 1][x] != 'E')
		materials_drop_check(d, x, y + 1);
	if (d->temp_map[y - 1][x] != '1' && d->temp_map[y - 1][x] != '.'
		&& d->temp_map[y - 1][x] != 'P' && d->temp_map[y - 1][x] != 'P')
		materials_drop_check(d, x, y - 1);
	if (d->temp_map[y][x + 1] != '1' && d->temp_map[y][x + 1] != '.'
		&& d->temp_map[y][x + 1] != 'P' && d->temp_map[y][x + 1] != 'E')
		materials_drop_check(d, x + 1, y);
	else
	{
		d->temp_map[y][x] = '.';
		return ;
	}
}
