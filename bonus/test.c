/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:41:11 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/26 11:09:23 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	position_enemy(t_map *map)
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
			if (map->data[j][i] == 'N')
			{
				ft_move(map, j, i);
				break;
			}
			i++;
		}
		j++;
	}
}

void	move_enemy_left(t_map *map, int y, int x)
{
	map->data[y][x - 1] = 'N';
	map->data[y][x] = '0';
	mlx_clear_window(map->mlx, map->win);
	ft_draw(map);
}

void	move_enemy_right(t_map *map, int y, int x)
{
	map->data[y][x + 1] = 'N';
	map->data[y][x] = '0';
	mlx_clear_window(map->mlx, map->win);
	ft_draw(map);
}

void	ft_move(t_map *map, int pos_y, int pos_x)
{
	if (map->eny == 0)
	{
		if (map->data[pos_y][pos_x + 1] == 'P')
			msg_end_game("\033[0;31m≈≈≈≈≈≈≈≈≈≈ YOU LOSE ≈≈≈≈≈≈≈≈≈≈", 1);
		if (map->data[pos_y][pos_x + 1] == '1'
		|| map->data[pos_y][pos_x + 1] == 'E'
		|| map->data[pos_y][pos_x + 1] == 'C')
		{
			map->eny = 1;
		}
		if (map->data[pos_y][pos_x + 1] == '0')
			move_enemy_right(map, pos_y, pos_x);
	}
	if (map->eny == 1)
	{
		if (map->data[pos_y][pos_x - 1] == '1'
		|| map->data[pos_y][pos_x - 1] == 'E'
		|| map->data[pos_y][pos_x - 1] == 'C')
		{
			map->eny = 0;
		}
		if (map->data[pos_y][pos_x - 1] == '0')
			move_enemy_left(map, pos_y, pos_x);
		if (map->data[pos_y][pos_x - 1] == 'P')
			msg_end_game("\033[0;31m≈≈≈≈≈≈≈≈≈≈ YOU LOSE ≈≈≈≈≈≈≈≈≈≈", 1);
	}
}
