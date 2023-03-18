/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:06:07 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/18 19:14:25 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_left(t_map *map)
{
	map->pl = 1;
	position_player(map);
	number_of_coins(map, map->data);
	if (map->data[map->plyer_y][map->plyer_x - 1] == 'E')
	{
		if (map->coins == 0)
		{
			ft_printf("\033[0;32m>>>>>>>YOU WIN<<<<<<<<<<\n");
			exit(0);
		}
	}
	else if (map->data[map->plyer_y][map->plyer_x - 1] == 'C')
		move_0(map);
	else if (map->data[map->plyer_y][map->plyer_x - 1] == '0')
	{
		move_left(map, 0);
		map->moves++;
		ft_printf("%d\n", map->moves);
	}
}

void	move_player_right(t_map *map)
{
	map->pl = 2;
	position_player(map);
	number_of_coins(map, map->data);
	if (map->data[map->plyer_y][map->plyer_x + 1] == 'E')
	{
		if (map->coins == 0)
		{
			ft_printf("\033[0;32m>>>>>>>YOU WIN<<<<<<<<<<\n");
			exit(0);
		}
	}
	else if (map->data[map->plyer_y][map->plyer_x + 1] == 'C')
		move_1(map);
	else if (map->data[map->plyer_y][map->plyer_x + 1] == '0')
	{
		move_right(map, 0);
		map->moves++;
		ft_printf("%d\n", map->moves);
	}
}

void	move_player_up(t_map *map)
{
	map->pl = 3;
	position_player(map);
	number_of_coins(map, map->data);
	if (map->data[map->plyer_y - 1][map->plyer_x] == 'E')
	{
		if (map->coins == 0)
		{
			ft_printf("\033[0;32m>>>>>>>YOU WIN<<<<<<<<<<\n");
			exit(0);
		}
	}
	else if (map->data[map->plyer_y - 1][map->plyer_x] == 'C')
		move_2(map);
	else if (map->data[map->plyer_y - 1][map->plyer_x] == '0')
	{
		move_up(map, 0);
		map->moves++;
		ft_printf("%d\n", map->moves);
	}
}

void	move_player_down(t_map *map)
{
	map->pl = 0;
	position_player(map);
	number_of_coins(map, map->data);
	if (map->data[map->plyer_y + 1][map->plyer_x] == 'E')
	{
		if (map->coins == 0)
		{
			ft_printf("\033[0;32m>>>>>>>YOU WIN<<<<<<<<<<\n");
			exit(0);
		}
	}
	else if (map->data[map->plyer_y + 1][map->plyer_x] == 'C')
		move_3(map);
	else if (map->data[map->plyer_y + 1][map->plyer_x] == '0')
	{
		move_down(map, 0);
		map->moves++;
		ft_printf("%d\n", map->moves);
	}
}
