/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:13:25 by hozdemir          #+#    #+#             */
/*   Updated: 2023/01/04 13:06:34 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ifmai_bonus.h"

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
		update_step(d);
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
	if (d->count_exit == 0)
	{
		mlx_destroy_window(d->mlx, d->win);
		exit(0);
	}
}

static void	key_hook2(int keycode, t_data *d)
{
	if ((keycode == D || keycode == RIGHT)
		&& step(d, d->map, d->p.y_player, d->p.x_player + 1))
	{
		key_render_parse(keycode, d);
		d->map[d->p.y_player][d->p.x_player] = '0';
		d->p.x_player += 1;
		d->map[d->p.y_player][d->p.x_player] = 'P';
		ft_printf("Step : %d\n", d->step_count);
		mlx_string_put(d->mlx, d->win, 0, 32, WHITE, d->steps);
	}
	if ((keycode == A || keycode == LEFT)
		&& step(d, d->map, d->p.y_player, d->p.x_player - 1))
	{
		key_render_parse(keycode, d);
		d->map[d->p.y_player][d->p.x_player] = '0';
		d->p.x_player -= 1;
		d->map[d->p.y_player][d->p.x_player] = 'P';
		ft_printf("Step : %d\n", d->step_count);
		mlx_string_put(d->mlx, d->win, 0, 32, WHITE, d->steps);
	}
	key_hook3(keycode, d);
}

int	key_hook(int keycode, t_data *d)
{
	if ((keycode == W || keycode == UP)
		&& step(d, d->map, d->p.y_player - 1, d->p.x_player))
	{
		key_render_parse(keycode, d);
		d->map[d->p.y_player][d->p.x_player] = '0';
		d->p.y_player -= 1;
		d->map[d->p.y_player][d->p.x_player] = 'P';
		ft_printf("Step : %d\n", d->step_count);
		mlx_string_put(d->mlx, d->win, 0, 32, WHITE, d->steps);
	}
	if ((keycode == S || keycode == DOWN)
		&& step(d, d->map, d->p.y_player + 1, d->p.x_player))
	{
		key_render_parse(keycode, d);
		d->map[d->p.y_player][d->p.x_player] = '0';
		d->p.y_player += 1;
		d->map[d->p.y_player][d->p.x_player] = 'P';
		ft_printf("Step : %d\n", d->step_count);
		mlx_string_put(d->mlx, d->win, 0, 32, WHITE, d->steps);
	}
	key_hook2(keycode, d);
	return (0);
}
