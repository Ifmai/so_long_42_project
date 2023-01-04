/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 07:01:02 by hozdemir          #+#    #+#             */
/*   Updated: 2023/01/04 14:34:36 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ifmai_bonus.h"

void	update_step(t_data *d)
{
	char	*base;
	char	*step_count;

	base = ft_strdup(" Step :");
	step_count = ft_itoa(d->step_count);
	base = ft_strjoin_get_next_line(base, step_count);
	d->steps = base;
}

void	clear_data(t_data *data)
{
	data->mlx = mlx_init();
	data->w_map = 0;
	data->h_map = 0;
	data->map = 0;
	data->win = 0;
	data->collect.x = 0;
	data->collect.y = 0;
	data->p.x_player = 0;
	data->p.y_player = 0;
	data->e.x = 0;
	data->e.y = 0;
	data->count_collectable = 0;
	data->count_player = 0;
	data->count_exit = 0;
	data->temp_count_coll = 0;
	data->temp_count_exit = 0;
	data->step_count = 0;
	data->count_enemy = 0;
	data->e.check_wall = 0;
	data->steps = " Step : 0";
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

void	error_print(char *str)
{
	ft_printf("%s", str);
	exit(0);
}
