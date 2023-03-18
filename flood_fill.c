/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 00:22:36 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/15 15:27:18 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *map, int pos_x, int pos_y)
{
	if (pos_x < 0 || pos_y < 0 || pos_x >= map->x || pos_y >= map->y
		|| map->data_tmp[pos_y][pos_x] == '1'
		|| map->data_tmp[pos_y][pos_x] == 'H')
		return ;
	if (map->data_tmp[pos_y][pos_x] == 'E')
	{
		map->exit = 1;
		return ;
	}
	map->data_tmp[pos_y][pos_x] = 'H';
	flood_fill(map, pos_x - 1, pos_y);
	flood_fill(map, pos_x + 1, pos_y);
	flood_fill(map, pos_x, pos_y - 1);
	flood_fill(map, pos_x, pos_y + 1);
}

void	ft_alloc_map_tmp(t_map *map)
{
	int	i;

	map->data_tmp = malloc(sizeof(char *) * (map->y + 1));
	if (!map->data_tmp)
		return ;
	i = 0;
	// printf("%s | %p\n", map->data[i] , map->data_tmp[i]);
	while (i < map->y)
	{
		map->data_tmp[i] = my_strdup(map->data[i]);
		i++;
	}
	// printf("%s | %p\n", map->data[0] , map->data_tmp[0]);
	map->data_tmp[i] = NULL;
}

void	position_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < map->y)
	{
		i = 0;
		while (i < map->x)
		{
			if (map->data[j][i] == 'P')
			{
				map->plyer_x = i;
				map->plyer_y = j;
				break ;
			}
			i++;
		}
		j++;
	}
}

void	number_of_coins(t_map *map)
{
	int	i;
	int	j;

	j = 1;
	while (j < map->y)
	{
		i = 0;
		while (i < map->x)
		{
			if (map->data_tmp[j][i] == 'C')
				map->coins++;
			i++;
		}
		j++;
	}
}

void	valid_path(t_map *map)
{
	number_of_coins(map);
	if (map->coins || map->exit != 1)
		exit_func("\033[0;31minvalid path in the map🙂");
}
