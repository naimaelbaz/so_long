/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:50:40 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/18 08:20:31 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_map(t_map *map, t_var *v)
{
	v->i = 0;
	v->y = 0;
	while (map->data[v->i])
	{
		v->j = 0;
		v->x = 0;
		while (map->data[v->i][v->j])
		{
			if (map->data[v->i][v->j] == '0')
				mlx_put_image_to_window(map->d.mlx, map->d.win, map->d.floor, v->x, v->y);
			else if (map->data[v->i][v->j] == '1')
				mlx_put_image_to_window(map->d.mlx, map->d.win, map->d.wall, v->x, v->y);
			else if (map->data[v->i][v->j] == 'E')
				mlx_put_image_to_window(map->d.mlx, map->d.win, map->d.exit_a, v->x, v->y);
			else if (map->data[v->i][v->j] == 'P')
				mlx_put_image_to_window(map->d.mlx, map->d.win, map->d.player, v->x, v->y);
			else if (map->data[v->i][v->j] == 'C')
				mlx_put_image_to_window(map->d.mlx, map->d.win, map->d.coin_a, v->x, v->y);
			v->x += 64;
			v->j++;
		}
		v->y += 64;
		v->i++;
	}
}

// void	move_to_left(t_mlx *param)
// {
// 	if (param->map.data[param->map.y][param->map.x])
// }

int	on_click(int keycode, void *param)
{
	(void)param;
	if (keycode == 0 || keycode == 123)
	{
		printf("liser\n");
	}
	else if (keycode == 1 || keycode == 125)
		printf("ltht\n");
	else if (keycode == 2 || keycode == 124)
		printf("limn\n");
	else if (keycode == 13 || keycode == 126)
		printf("lfo9\n");
	return (0);
}

void	insert_image(t_map *map)
{
	int	a;
	int	b;

	map->d.floor = mlx_xpm_file_to_image(map->d.mlx,
			"./files/floor.xpm", &a, &b);
	map->d.coin_a = mlx_xpm_file_to_image(map->d.mlx,
			"./files/collect.xpm", &a, &b);
	map->d.coin_b = mlx_xpm_file_to_image(map->d.mlx,
			"./files/coin_b.xpm", &a, &b);
	map->d.exit_a = mlx_xpm_file_to_image(map->d.mlx,
			"./files/exit_a.xpm", &a, &b);
	map->d.exit_b = mlx_xpm_file_to_image(map->d.mlx,
			"./files/exit_b.xpm", &a, &b);
	map->d.wall = mlx_xpm_file_to_image(map->d.mlx,
			"./files/wall.xpm", &a, &b);
	map->d.player = mlx_xpm_file_to_image(map->d.mlx,
			"./files/player1.xpm", &a, &b);
}

// void	ft_data_map()

void	ft_new_wind(t_map *map, t_var *v)
{
	map->d.mlx = mlx_init();
	map->d.win = mlx_new_window(map->d.mlx, map->x * 64,
			map->y * 64, "Tutorial Window");
	insert_image(map);
	ft_draw_map(map, v);
	mlx_key_hook(map->d.win, on_click, &map);
	mlx_loop(map->d.mlx);
}
