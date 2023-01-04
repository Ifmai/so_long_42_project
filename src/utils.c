/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 07:01:02 by hozdemir          #+#    #+#             */
/*   Updated: 2022/12/26 03:56:30 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ifmai.h"

void	clear_data(t_data *data)
{
	data->mlx = mlx_init();
	data->w_map = 0;
	data->h_map = 0;
	data->map = 0;
	data->win = 0;
	data->collect.x_collectable = 0;
	data->collect.y_collectable = 0;
	data->player.x_player = 0;
	data->player.y_player = 0;
	data->count_collectable = 0;
	data->count_player = 0;
	data->count_exit = 0;
	data->temp_count_coll = 0;
	data->temp_count_exit = 0;
	data->step_count = 0;
}

int	check_path(char *path)
{
	char	*check;
	int		i;

	i = 0;
	check = "reb.";
	while (path[i + 1] != 0)
		i++;
	while (*check)
	{
		if (path[i] != *check)
			return (1);
		check++;
		i--;
	}
	return (0);
}

void	materials_count_check(t_data *data)
{
	int	i;

	i = 0;
	if (data->count_collectable < 1
		|| data->count_collectable != data->temp_count_coll)
		error_print(COLLERR);
	if (data->count_exit != 1 || data->count_exit != data->temp_count_exit)
		error_print(EXITERR);
	if (data->count_player != 1)
		error_print(PLAYERERR);
	while (data->temp_map[i])
	{
		free(data->temp_map[i]);
		i++;
	}
	free(data->temp_map);
	data->temp_count_coll = 0;
	data->temp_count_exit = 0;
}

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
				d->collect.x_collectable[col_index] = j;
				d->collect.y_collectable[col_index] = i;
				col_index++;
			}
			if (d->map[i][j] != 'P' && d->map[i][j] != '0' &&
			d->map[i][j] != '1' && d->map[i][j] != 'E' && d->map[i][j] != 'C')
				error_print(MAPVER);
			j++;
		}
		i++;
	}
}

void	error_print(char *str)
{
	ft_printf("%s", str);
	exit(0);
}
