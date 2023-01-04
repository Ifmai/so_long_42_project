/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:49:07 by hozdemir          #+#    #+#             */
/*   Updated: 2023/01/04 15:26:59 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ifmai_bonus.h"

int	render_parse(t_data *d)
{
	int	i;
	int	j;

	d->ry = 0;
	i = -1;
	mlx_clear_window(d->mlx, d->win);
	while (d->map[++i])
	{
		mlx_string_put(d->mlx, d->win, 0, 32, WHITE, d->steps);
		d->rx = 0;
		j = 0;
		loop_map_parse(-1, &i, &j, d);
		d->ry += 64;
	}
	return (0);
}

void	key_render_parse(int keycode, t_data *d)
{
	int	i;
	int	j;

	d->ry = 0;
	i = -1;
	mlx_clear_window(d->mlx, d->win);
	while (d->map[++i])
	{
		d->rx = 0;
		j = 0;
		loop_map_parse(keycode, &i, &j, d);
		d->ry += 64;
	}
}

void	render_collect(t_data *d, int *x, int *y)
{
	static int	fr = 0;

	mlx_put_image_to_window(d->mlx, d->win, d->collect.img[fr], *x, *y);
	usleep(25000);
	fr++;
	if (fr % 16 == 0)
		fr = 0;
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
