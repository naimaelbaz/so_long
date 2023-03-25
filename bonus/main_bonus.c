/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:44:54 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/25 14:06:53 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_new_wind(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		exit(1);
	map->win = mlx_new_window(map->mlx, map->x * 64,
			map->y * 64, "so_long");
	insert_image(map);
	ft_draw(map);
	mlx_hook(map->win, 2, 0, on_click, map);
	mlx_loop_hook(map->mlx, ft_animation, map);
	mlx_loop(map->mlx);
}

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
		free_map(map.data_tmp, map.y);
		ft_new_wind(&map);
		free_map(map.data, map.y);
	}
	return (0);
}
