/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:07:28 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/18 19:17:06 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_0(t_map *map)
{
	if (map->coins)
	{
		move_left(map, 0);
		map->coins--;
		if (!map->coins)
			move_left(map, 1);
	}
	map->moves++;
	ft_printf("%d\n", map->moves);
}

void	move_1(t_map *map)
{
	if (map->coins)
	{
		move_right(map, 0);
		map->coins--;
		if (!map->coins)
			move_right(map, 1);
	}
	map->moves++;
	ft_printf("%d\n", map->moves);
}

void	move_2(t_map *map)
{
	if (map->coins)
	{
		move_up(map, 0);
		map->coins--;
		if (!map->coins)
			move_up(map, 1);
	}
	map->moves++;
	ft_printf("%d\n", map->moves);
}

void	move_3(t_map *map)
{
	if (map->coins)
	{
		move_down(map, 0);
		map->coins--;
		if (!map->coins)
			move_down(map, 1);
	}
	map->moves++;
	ft_printf("%d\n", map->moves);
}
