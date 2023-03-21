/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:06:07 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/21 13:26:42 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	msg_end_game(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void	move_player_left(t_map *map)
{
	map->pl = map->player_l;
	position_player(map);
	number_of_coins(map, map->data);
	if (map->data[map->plyer_y][map->plyer_x - 1] == 'E')
	{
		if (map->coins == 0)
			msg_end_game("\033[0;32m>>>>>>> YOU WIN <<<<<<<");
	}
	else if (map->data[map->plyer_y][map->plyer_x - 1] == 'C')
	{
		map->moves++;
		move_0(map);
	}
	else if (map->data[map->plyer_y][map->plyer_x - 1] == '0')
	{
		map->moves++;
		move_left(map);
	}
}

void	move_player_right(t_map *map)
{
	map->pl = map->player_r;
	position_player(map);
	number_of_coins(map, map->data);
	if (map->data[map->plyer_y][map->plyer_x + 1] == 'E')
	{
		if (map->coins == 0)
			msg_end_game("\033[0;32m>>>>>>> YOU WIN <<<<<<<");
	}
	else if (map->data[map->plyer_y][map->plyer_x + 1] == 'C')
	{
		map->moves++;
		move_1(map);
	}
	else if (map->data[map->plyer_y][map->plyer_x + 1] == '0')
	{
		map->moves++;
		move_right(map);
	}
}

void	move_player_up(t_map *map)
{
	map->pl = map->player_u;
	position_player(map);
	number_of_coins(map, map->data);
	if (map->data[map->plyer_y - 1][map->plyer_x] == 'E')
	{
		if (map->coins == 0)
			msg_end_game("\033[0;32m>>>>>>> YOU WIN <<<<<<<");
	}
	else if (map->data[map->plyer_y - 1][map->plyer_x] == 'C')
	{
		map->moves++;
		move_2(map);
	}
	else if (map->data[map->plyer_y - 1][map->plyer_x] == '0')
	{
		map->moves++;
		move_up(map);
	}
}

void	move_player_down(t_map *map)
{
	map->pl = map->player_d;
	position_player(map);
	number_of_coins(map, map->data);
	if (map->data[map->plyer_y + 1][map->plyer_x] == 'E')
	{
		if (map->coins == 0)
			msg_end_game("\033[0;32m>>>>>>> YOU WIN <<<<<<<");
	}
	else if (map->data[map->plyer_y + 1][map->plyer_x] == 'C')
	{
		map->moves++;
		move_3(map);
	}
	else if (map->data[map->plyer_y + 1][map->plyer_x] == '0')
	{
		map->moves++;
		move_down(map);
	}
}
