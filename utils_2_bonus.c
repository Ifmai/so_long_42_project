/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:49:07 by hozdemir          #+#    #+#             */
/*   Updated: 2022/12/26 17:33:38 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ifmai_bonus.h"

void	add_player_photo(t_data *d, int *x, int *y)
{
	d->p.b_img[0] = mlx_xpm_file_to_image(d->mlx, HEROXPM1, x, y);
	d->p.b_img[1] = mlx_xpm_file_to_image(d->mlx, HEROXPM2, x, y);
	d->p.b_img[2] = mlx_xpm_file_to_image(d->mlx, HEROXPM3, x, y);
	d->p.b_img[3] = mlx_xpm_file_to_image(d->mlx, HEROXPM4, x, y);
	d->p.r_img[0] = mlx_xpm_file_to_image(d->mlx, HERORIGHT1, x, y);
	d->p.r_img[1] = mlx_xpm_file_to_image(d->mlx, HERORIGHT2, x, y);
	d->p.r_img[2] = mlx_xpm_file_to_image(d->mlx, HERORIGHT3, x, y);
	d->p.r_img[3] = mlx_xpm_file_to_image(d->mlx, HERORIGHT4, x, y);
	d->p.r_img[4] = mlx_xpm_file_to_image(d->mlx, HERORIGHT5, x, y);
	d->p.r_img[5] = mlx_xpm_file_to_image(d->mlx, HERORIGHT6, x, y);
	d->p.r_img[6] = mlx_xpm_file_to_image(d->mlx, HERORIGHT7, x, y);
	d->p.r_img[7] = mlx_xpm_file_to_image(d->mlx, HERORIGHT8, x, y);
	d->p.l_img[0] = mlx_xpm_file_to_image(d->mlx, HEROLEFT1, x, y);
	d->p.l_img[1] = mlx_xpm_file_to_image(d->mlx, HEROLEFT2, x, y);
	d->p.l_img[2] = mlx_xpm_file_to_image(d->mlx, HEROLEFT3, x, y);
	d->p.l_img[3] = mlx_xpm_file_to_image(d->mlx, HEROLEFT4, x, y);
	d->p.l_img[4] = mlx_xpm_file_to_image(d->mlx, HEROLEFT5, x, y);
	d->p.l_img[5] = mlx_xpm_file_to_image(d->mlx, HEROLEFT6, x, y);
	d->p.l_img[6] = mlx_xpm_file_to_image(d->mlx, HEROLEFT7, x, y);
	d->p.l_img[7] = mlx_xpm_file_to_image(d->mlx, HEROLEFT8, x, y);
}

void	add_player_jump(t_data *d, int *x, int *y)
{
	d->p.j_img[0] = mlx_xpm_file_to_image(d->mlx, HEROJUMP1, x, y);
	d->p.j_img[1] = mlx_xpm_file_to_image(d->mlx, HEROJUMP2, x, y);
	d->p.j_img[2] = mlx_xpm_file_to_image(d->mlx, HEROJUMP3, x, y);
	d->p.j_img[3] = mlx_xpm_file_to_image(d->mlx, HEROJUMP4, x, y);
	d->p.j_img[4] = mlx_xpm_file_to_image(d->mlx, HEROJUMP5, x, y);
	d->p.j_img[5] = mlx_xpm_file_to_image(d->mlx, HEROJUMP6, x, y);
	d->p.j_img[6] = mlx_xpm_file_to_image(d->mlx, HEROJUMP7, x, y);
	d->p.j_img[7] = mlx_xpm_file_to_image(d->mlx, HEROJUMP8, x, y);
}

void	add_enemy_photo(t_data *d, int *x, int *y)
{
	d->e.img[0] = mlx_xpm_file_to_image(d->mlx, ENEMY1, x, y);
	d->e.img[1] = mlx_xpm_file_to_image(d->mlx, ENEMY2, x, y);
	d->e.img[2] = mlx_xpm_file_to_image(d->mlx, ENEMY3, x, y);
	d->e.img[3] = mlx_xpm_file_to_image(d->mlx, ENEMY4, x, y);
	d->e.img[4] = mlx_xpm_file_to_image(d->mlx, ENEMY5, x, y);
	d->e.img[5] = mlx_xpm_file_to_image(d->mlx, ENEMY6, x, y);
	d->e.img[6] = mlx_xpm_file_to_image(d->mlx, ENEMY7, x, y);
	d->e.img[7] = mlx_xpm_file_to_image(d->mlx, ENEMY8, x, y);
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
