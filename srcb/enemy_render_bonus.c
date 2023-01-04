/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_render_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:29:36 by hozdemir          #+#    #+#             */
/*   Updated: 2023/01/04 15:17:09 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ifmai_bonus.h"

static void	check_wall_enemy(t_data *d, int i)
{
	if (d->map[d->e.y[i]][d->e.x[i] - 1] == 'P'
	|| d->map[d->e.y[i]][d->e.x[i] + 1] == 'P')
		exit(0);
	if (d->map[d->e.y[i]][d->e.x[i] - 1] == '1'
	|| d->map[d->e.y[i]][d->e.x[i] - 1] == 'C'
	|| d->map[d->e.y[i]][d->e.x[i] - 1] == 'E'
	|| d->map[d->e.y[i]][d->e.x[i] - 1] == 'H')
		d->e.check_wall[i] = 1;
	else if (d->map[d->e.y[i]][d->e.x[i] + 1] == '1'
	|| d->map[d->e.y[i]][d->e.x[i] + 1] == 'C'
	|| d->map[d->e.y[i]][d->e.x[i] + 1] == 'E'
	|| d->map[d->e.y[i]][d->e.x[i] + 1] == 'H')
		d->e.check_wall[i] = 0;
}

static void	enemy_x_y(t_data *d, int t_o, int indx)
{
	if (t_o == 0)
	{
		d->map[d->e.y[indx]][d->e.x[indx]] = '0';
		d->e.x[indx] -= 1;
		d->map[d->e.y[indx]][d->e.x[indx]] = 'H';
	}
	else
	{
		d->map[d->e.y[indx]][d->e.x[indx]] = '0';
		d->e.x[indx] += 1;
		d->map[d->e.y[indx]][d->e.x[indx]] = 'H';
	}
}

static int	check_path_selection(t_data *d, int i)
{
	if (d->map[d->e.y[i]][d->e.x[i] - 1] != '1'
		&& d->map[d->e.y[i]][d->e.x[i] - 1] != 'C'
		&& d->map[d->e.y[i]][d->e.x[i] - 1] != 'E'
		&& d->e.check_wall[i] == 0)
		return (1);
	if (d->map[d->e.y[i]][d->e.x[i] + 1] != '1'
		&& d->map[d->e.y[i]][d->e.x[i] + 1] != 'C'
		&& d->map[d->e.y[i]][d->e.x[i] + 1] != 'E'
		&& d->e.check_wall[i] == 1)
		return (2);
	return (0);
}

void	render_enemy(t_data *d, int *x, int *y)
{
	int	i;
	int	p;

	p = 8;
	i = 0;
	while (i < d->count_enemy)
	{
		check_wall_enemy(d, i);
		if (check_path_selection(d, i) == 1)
			mlx_put_image_to_window(d->mlx,
				d->win, d->e.img[d->e.fr[i]], *x - p, *y);
		else if (check_path_selection(d, i) == 2)
			mlx_put_image_to_window(d->mlx, d->win,
				d->e.r_img[d->e.fr[i]], *x + p, *y);
		usleep(10000);
		if (d->e.fr[i] % 7 == 0)
		{
			enemy_x_y(d, d->e.check_wall[i], i);
			d->e.fr[i] = 0;
		}
		d->e.fr[i]++;
		i++;
	}
}
