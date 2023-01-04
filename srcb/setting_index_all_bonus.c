/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_index_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:22:14 by hozdemir          #+#    #+#             */
/*   Updated: 2022/12/29 00:58:44 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ifmai_bonus.h"

void	setting_collect_indeks(t_data *d)
{
	int	i;
	int	j;
	int	col_index;

	col_index = 0;
	i = 0;
	while (d->map[i] != 0)
	{
		j = 0;
		while (d->map[i][j] != 0 && d->map[i][j] != '\n')
		{
			if (d->map[i][j] == 'C')
			{
				d->collect.x[col_index] = j;
				d->collect.y[col_index] = i;
				col_index++;
			}
			if (d->map[i][j] != 'P' && d->map[i][j] != '0' &&
			d->map[i][j] != '1' && d->map[i][j] != 'E' && d->map[i][j] != 'C'
			&& d->map[i][j] != 'H')
				error_print(MAPVER);
			j++;
		}
		i++;
	}
}

void	setting_player_indeks(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->map[i] != 0)
	{
		j = 0;
		while (d->map[i][j] != 0 && d->map[i][j] != '\n')
		{
			if (d->map[i][j] == 'P')
			{
				d->p.x_player = j;
				d->p.y_player = i;
			}
			if (d->map[i][j] != 'P' && d->map[i][j] != '0' &&
			d->map[i][j] != '1' && d->map[i][j] != 'E' && d->map[i][j] != 'C'
			&& d->map[i][j] != 'H')
				error_print(MAPVER);
			j++;
		}
		i++;
	}
}

void	setting_enemy_indeks(t_data *d)
{
	int	i;
	int	j;
	int	en_index;

	en_index = 0;
	i = 0;
	while (d->map[i] != 0)
	{
		j = 0;
		while (d->map[i][j] != 0 && d->map[i][j] != '\n')
		{
			if (d->map[i][j] == 'H')
			{
				d->e.x[en_index] = j;
				d->e.y[en_index] = i;
				en_index++;
			}
			if (d->map[i][j] != 'P' && d->map[i][j] != '0' &&
			d->map[i][j] != '1' && d->map[i][j] != 'E' && d->map[i][j] != 'C'
			&& d->map[i][j] != 'H')
				error_print(MAPVER);
			j++;
		}
		i++;
	}
}
