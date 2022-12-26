/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_all_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:24:15 by hozdemir          #+#    #+#             */
/*   Updated: 2022/12/26 03:48:22 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ifmai.h"

void	map_materials(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != 0)
	{
		j = 0;
		while (data->map[i][j] != 0 && data->map[i][j] != '\n')
		{
			if (data->map[i][j] == 'E')
				data->count_exit += 1;
			if (data->map[i][j] == 'P')
			{
				data->player.x_player = j;
				data->player.y_player = i;
				data->count_player += 1;
			}
			if (data->map[i][j] == 'C')
				data->count_collectable += 1;
			j++;
		}
		i++;
	}
}

void	map_wall_check(t_data *data)
{
	int		i;

	i = 0;
	while (data->map[i])
	{
		if (data->map[i][0] != '1' || data->map[i][data->w_map - 1] != '1')
			error_print(WALLERR);
		i++;
	}
	i = 0;
	while (data->map[0][i] != 0 && data->map[0][i] != '\n')
	{
		if (data->map[0][i] != '1' || data->map[data->h_map - 1][i] != '1')
			error_print(WALLERR);
		i++;
	}
}

void	map_create(t_data *data, char *path)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	data->map = ft_calloc(sizeof(char *), data->h_map + 1);
	while (i < data->h_map)
	{
		data->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	temp_map_create(t_data *data, char *path)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	data->temp_map = ft_calloc(sizeof(char *), data->h_map + 1);
	while (i < data->h_map)
	{
		data->temp_map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	map_size(t_data *data, char *path)
{
	int		fd;
	char	*a;

	fd = open(path, O_RDONLY);
	a = get_next_line(fd);
	data->w_map = ft_strlen(a);
	free(a);
	while (1)
	{
		a = get_next_line(fd);
		data->h_map += 1;
		if (!a)
			break ;
		if ((int)ft_strlen(a) != data->w_map)
			error_print(MAPERR);
		free(a);
	}
	close(fd);
}
