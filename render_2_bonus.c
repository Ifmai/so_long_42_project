/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:29:36 by hozdemir          #+#    #+#             */
/*   Updated: 2022/12/26 17:37:18 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ifmai_bonus.h"

void	render_hero(t_data *d, int *x, int *y)
{
	static int	*fr = 0;
	int i;

	i = 0;
	while(i < d->count_enemy)
	{
		if(d->map[d->e.y[i]][d->e.x[i]] != '1'
		&& d->map[d->e.y[i]][d->e.x[i]] != 'C' && d->map[d->e.y[i]][d->e.x[i]] != 'E')
		{
			mlx_put_image_to_window(d->mlx, d->win, d->p.b_img[fr], *x, *y);
			usleep(150000);
			if(fr % 8 == 0)
				fr = 0;
		}
		i++;
		fr++;
	}
}
		