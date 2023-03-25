/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:41:11 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/25 22:06:14 by nel-baz          ###   ########.fr       */
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
				printf("i == %d\n",i);
				printf("j == %d\n",j);
				ft_move(map, j, i);
			}
			i++;
		}
		j++;
	}
}

void	move_enemy_left(t_map *map)
{
	map->data[map->enemy_y][map->enemy_x - 1] = 'N';
	map->data[map->enemy_y][map->enemy_x] = '0';
	mlx_clear_window(map->mlx, map->win);
	ft_draw(map);
}

void	move_enemy_right(t_map *map)
{
	map->data[map->enemy_y][map->enemy_x + 1] = 'N';
	map->data[map->enemy_y][map->enemy_x] = '0';
	mlx_clear_window(map->mlx, map->win);
	ft_draw(map);
}

void	ft_move(t_map *map, int pos_y, int pos_x)
{
	if (map->eny == 0)
	{
		if (map->data[pos_y][pos_x] == 'P')
			msg_end_game("you lose", 1);
		if (map->data[pos_y][pos_x + 1] == '1'
		|| map->data[pos_y][pos_x + 1] == 'E'
		|| map->data[pos_y][pos_x + 1] == 'C')
		{
			map->eny = 1;
		}
		if (map->data[pos_y][pos_x + 1] == '0')
			move_enemy_right(map);
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
			move_enemy_left(map);
		if (map->data[pos_y][pos_x - 1] == 'P')
			msg_end_game("you lose", 1);
	}
}
