/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_photo_all_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:52:09 by hozdemir          #+#    #+#             */
/*   Updated: 2023/01/04 04:14:11 by hozdemir         ###   ########.fr       */
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
	d->e.r_img[0] = mlx_xpm_file_to_image(d->mlx, RENEMY1, x, y);
	d->e.r_img[1] = mlx_xpm_file_to_image(d->mlx, RENEMY2, x, y);
	d->e.r_img[2] = mlx_xpm_file_to_image(d->mlx, RENEMY3, x, y);
	d->e.r_img[3] = mlx_xpm_file_to_image(d->mlx, RENEMY4, x, y);
	d->e.r_img[4] = mlx_xpm_file_to_image(d->mlx, RENEMY5, x, y);
	d->e.r_img[5] = mlx_xpm_file_to_image(d->mlx, RENEMY6, x, y);
	d->e.r_img[6] = mlx_xpm_file_to_image(d->mlx, RENEMY7, x, y);
	d->e.r_img[7] = mlx_xpm_file_to_image(d->mlx, RENEMY8, x, y);
}

void	add_dead_player(t_data *d, int *x, int *y)
{
	d->p.d_img[0] = mlx_xpm_file_to_image(d->mlx, DEAD1, x, y);
	d->p.d_img[1] = mlx_xpm_file_to_image(d->mlx, DEAD2, x, y);
	d->p.d_img[2] = mlx_xpm_file_to_image(d->mlx, DEAD3, x, y);
	d->p.d_img[3] = mlx_xpm_file_to_image(d->mlx, DEAD4, x, y);
	d->p.d_img[4] = mlx_xpm_file_to_image(d->mlx, DEAD5, x, y);
	d->p.d_img[5] = mlx_xpm_file_to_image(d->mlx, DEAD6, x, y);
	d->p.d_img[6] = mlx_xpm_file_to_image(d->mlx, DEAD7, x, y);
}

void	add_coll_photo(t_data *d, int *x, int *y)
{
	d->collect.img[0] = mlx_xpm_file_to_image(d->mlx, COL1, x, y);
	d->collect.img[1] = mlx_xpm_file_to_image(d->mlx, COL2, x, y);
	d->collect.img[2] = mlx_xpm_file_to_image(d->mlx, COL3, x, y);
	d->collect.img[3] = mlx_xpm_file_to_image(d->mlx, COL4, x, y);
	d->collect.img[4] = mlx_xpm_file_to_image(d->mlx, COL5, x, y);
	d->collect.img[5] = mlx_xpm_file_to_image(d->mlx, COL6, x, y);
	d->collect.img[6] = mlx_xpm_file_to_image(d->mlx, COL7, x, y);
	d->collect.img[7] = mlx_xpm_file_to_image(d->mlx, COL8, x, y);
	d->collect.img[8] = mlx_xpm_file_to_image(d->mlx, COL9, x, y);
	d->collect.img[9] = mlx_xpm_file_to_image(d->mlx, COL10, x, y);
	d->collect.img[10] = mlx_xpm_file_to_image(d->mlx, COL11, x, y);
	d->collect.img[11] = mlx_xpm_file_to_image(d->mlx, COL12, x, y);
	d->collect.img[12] = mlx_xpm_file_to_image(d->mlx, COL13, x, y);
	d->collect.img[13] = mlx_xpm_file_to_image(d->mlx, COL14, x, y);
	d->collect.img[14] = mlx_xpm_file_to_image(d->mlx, COL15, x, y);
	d->collect.img[15] = mlx_xpm_file_to_image(d->mlx, COL16, x, y);
}
