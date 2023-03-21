/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:07:28 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/21 13:27:29 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_0(t_map *map)
{
	if (map->coins)
	{
		move_left(map);
		map->coins--;
		if (!map->coins)
		{
			map->ex = map->exit_b;
			move_left(map);
		}
	}
}

void	move_1(t_map *map)
{
	if (map->coins)
	{
		move_right(map);
		map->coins--;
		if (!map->coins)
		{
			map->ex = map->exit_b;
			move_right(map);
		}
	}
}

void	move_2(t_map *map)
{
	if (map->coins)
	{
		move_up(map);
		map->coins--;
		if (!map->coins)
		{
			map->ex = map->exit_b;
			move_up(map);
		}
	}
}

void	move_3(t_map *map)
{
	if (map->coins)
	{
		move_down(map);
		map->coins--;
		if (!map->coins)
		{
			map->ex = map->exit_b;
			move_down(map);
		}
	}
}
