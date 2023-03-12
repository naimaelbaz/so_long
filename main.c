/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:44:54 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/12 03:11:06 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void pop()
// {
// 	system("leaks so_long");
// }



void	parssing(char **argv, t_map *map)
{
	chack_map_name(argv);
	insert_var(map);
	ft_map_rectang(argv[1], map);
	ft_alloc_map(argv[1], map);
	check_map_walls(map);
	check_map_components(map);
	number_of_components(map);
	components_errors(map);
	position_player(map);
	ft_alloc_map_tmp(map);
	flood_fill(map, map->plyer_x, map->plyer_y);
	valid_path(map);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		parssing(argv, &map);
		// for (int i = 0; i < map.y ; i++)
		// 	printf("%s", map.data_tmp[i]);
		number_of_coins(&map, map.data_tmp);
		printf("\n%s\n",map.exit && !map.coins ? "yes" : "no!");
	}
	free_map(map.data, map.y);
	// atexit(pop);
	return (0);
}
