/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 04:44:14 by hozdemir          #+#    #+#             */
/*   Updated: 2022/12/26 13:41:42 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ifmai_bonus.h"

static void	render_hero(t_data *d, int *x, int *y)
{
	static int	fr = 0;
	
	mlx_put_image_to_window(d->mlx, d->win, d->p.b_img[fr], *x, *y);
	usleep(150000);
	fr++;
	if(fr % 3 == 0)
		fr = 0;
}

static void	key_render_hero_2(int keycode, t_data *d, int *x, int *y)
{
	static int	fr = 0;
	static int	fr2= 7;
	int	parse = 8;
	if (keycode == S || keycode == DOWN)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->p.j_img[fr2], *x, *y + parse);
		usleep(150000);
		fr2--;
		if(fr2 == 0)
			fr2 = 7;
	}
	if (keycode == W || keycode == UP)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->p.j_img[fr], *x, *y - parse);
		usleep(150000);
		fr++;
		if(fr % 8 == 0)
			fr = 0;
	}
}

static void	key_render_hero(int keycode, t_data *d, int *x, int *y)
{
	static int	fr = 0;
	int	parse = 8;

	if (keycode == A || keycode == LEFT)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->p.l_img[fr], *x - parse, *y);
		usleep(150000);
		fr++;
		if(fr % 8 == 0)
			fr = 0;
	}
	if (keycode == D || keycode == RIGHT)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->p.r_img[fr], *x + parse, *y);
		usleep(150000);
		fr++;
		if(fr % 8 == 0)
			fr = 0;
	}
	key_render_hero_2(keycode, d, x, y);
}

int render_parse(t_data *d)
{
	int	i;
	int	j;
	int x;
	int y;

	y = 0;
	i = -1;
	mlx_clear_window(d->mlx, d->win);
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
				render_hero(d, &x, &y);
			x += 64;
		}
		y += 64;
	}
	return (0);
}

void	key_render_parse(int keycode, t_data *d)
{
	int	i;
	int	j;
	int x;
	int y;

	y = 0;
	i = -1;
	mlx_clear_window(d->mlx, d->win);
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
				key_render_hero(keycode, d, &x, &y);
			x += 64;
		}
		y += 64;
	}
}
