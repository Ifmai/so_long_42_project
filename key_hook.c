/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:13:25 by hozdemir          #+#    #+#             */
/*   Updated: 2022/12/26 04:16:27 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ifmai.h"

static int	step(t_data *d, char **map, int y, int x)
{
	if (map[y][x] != '1')
	{
		if (map[y][x] == 'C')
			d->temp_count_coll += 1;
		if (map[y][x] == 'E' && d->temp_count_coll == d->count_collectable)
			d->count_exit = 0;
		else if (map[y][x] == 'E' && d->temp_count_coll != d->count_collectable)
			return (0);
		d->step_count += 1;
		return (1);
	}
	return (0);
}

static void	key_hook3(int keycode, t_data *d)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(d->mlx, d->win);
		exit(0);
	}
	mlx_clear_window(d->mlx, d->win);
	if (d->count_exit == 0)
	{
		mlx_destroy_window(d->mlx, d->win);
		exit(0);
	}
	else
		map_photo_parse(d, 0, 0);
}

static void	key_hook2(int keycode, t_data *d)
{
	if ((keycode == D || keycode == RIGHT)
		&& step(d, d->map, d->player.y_player, d->player.x_player + 1))
	{
		d->map[d->player.y_player][d->player.x_player] = '0';
		d->player.x_player += 1;
		d->map[d->player.y_player][d->player.x_player] = 'P';
		ft_printf("Step : %d\n", d->step_count);
	}
	if ((keycode == A || keycode == LEFT)
		&& step(d, d->map, d->player.y_player, d->player.x_player - 1))
	{
		d->map[d->player.y_player][d->player.x_player] = '0';
		d->player.x_player -= 1;
		d->map[d->player.y_player][d->player.x_player] = 'P';
		ft_printf("Step : %d\n", d->step_count);
	}
	key_hook3(keycode, d);
}

int	key_hook(int keycode, t_data *d)
{
	if ((keycode == W || keycode == UP)
		&& step(d, d->map, d->player.y_player - 1, d->player.x_player))
	{
		d->map[d->player.y_player][d->player.x_player] = '0';
		d->player.y_player -= 1;
		d->map[d->player.y_player][d->player.x_player] = 'P';
		ft_printf("Step : %d\n", d->step_count);
	}
	if ((keycode == S || keycode == DOWN)
		&& step(d, d->map, d->player.y_player + 1, d->player.x_player))
	{
		d->map[d->player.y_player][d->player.x_player] = '0';
		d->player.y_player += 1;
		d->map[d->player.y_player][d->player.x_player] = 'P';
		ft_printf("Step : %d\n", d->step_count);
	}
	key_hook2(keycode, d);
	return (0);
}
