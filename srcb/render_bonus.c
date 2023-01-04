/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 04:44:14 by hozdemir          #+#    #+#             */
/*   Updated: 2023/01/04 15:28:09 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ifmai_bonus.h"

static void	render_hero(t_data *d, int *x, int *y)
{
	static int	fr = 0;

	mlx_put_image_to_window(d->mlx, d->win, d->p.b_img[fr], *x, *y);
	usleep(50000);
	fr++;
	if (fr % 4 == 0)
		fr = 0;
}

static void	key_render_hero_2(int keycode, t_data *d, int *x, int *y)
{
	static int	fr = 0;
	static int	fr2 = 7;
	int			parse;

	parse = 8;
	if (keycode == S || keycode == DOWN)
	{
		mlx_put_image_to_window(d->mlx, d->win,
			d->p.j_img[fr2], *x, *y + parse);
		usleep(10000);
		fr2--;
		if (fr2 == 0)
			fr2 = 7;
	}
	if (keycode == W || keycode == UP)
	{
		mlx_put_image_to_window(d->mlx,
			d->win, d->p.j_img[fr], *x, *y - parse);
		usleep(10000);
		fr++;
		if (fr % 8 == 0)
			fr = 0;
	}
}

static void	key_render_hero(int keycode, t_data *d, int *x, int *y)
{
	static int	fr = 0;
	int			parse;

	parse = 8;
	if (keycode == A || keycode == LEFT)
	{
		mlx_put_image_to_window(d->mlx,
			d->win, d->p.l_img[fr], *x - parse, *y);
		usleep(10000);
		fr++;
		if (fr % 8 == 0)
			fr = 0;
	}
	if (keycode == D || keycode == RIGHT)
	{
		mlx_put_image_to_window(d->mlx,
			d->win, d->p.r_img[fr], *x + parse, *y);
		usleep(10000);
		fr++;
		if (fr % 8 == 0)
			fr = 0;
	}
	key_render_hero_2(keycode, d, x, y);
}

void	loop_map_parse(int keycode, int *i, int *j, t_data *d)
{
	while (d->map[*i][*j])
	{
		if (d->map[*i][*j] != '1')
			mlx_put_image_to_window(d->mlx, d->win, d->floor, d->rx, d->ry);
		if (d->map[*i][*j] == '1')
			mlx_put_image_to_window(d->mlx, d->win, d->wall_img, d->rx, d->ry);
		else if (d->map[*i][*j] == 'E')
			mlx_put_image_to_window(d->mlx, d->win, d->exit_img, d->rx, d->ry);
		else if (d->map[*i][*j] == 'C')
			render_collect(d, &d->rx, &d->ry);
		else if (d->map[*i][*j] == 'P' && keycode == -1)
			render_hero(d, &d->rx, &d->ry);
		else if (d->map[*i][*j] == 'P' && keycode != -1)
			key_render_hero(keycode, d, &d->rx, &d->ry);
		else if (d->map[*i][*j] == 'H')
			render_enemy(d, &d->rx, &d->ry);
		d->rx += 64;
		(*j)++;
	}
}
