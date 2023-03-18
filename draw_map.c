/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:50:40 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/18 19:22:56 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw(t_map *m)
{
	t_var	v;

	v.i = 0;
	v.y = 0;
	while (m->data[v.i])
	{
		v.j = 0;
		v.x = 0;
		while (m->data[v.i][v.j])
		{
			ft_draw_loop(m, &v);
			v.x += 64;
			v.j++;
		}
		v.y += 64;
		v.i++;
	}
}

int	on_click(int keycode, t_map *map)
{
	if (keycode == 0 || keycode == 123)
		move_player_left(map);
	else if (keycode == 1 || keycode == 125)
		move_player_down(map);
	else if (keycode == 2 || keycode == 124)
		move_player_right(map);
	else if (keycode == 13 || keycode == 126)
		move_player_up(map);
	else if (keycode == 53)
		exit(0);
	return (0);
}

void	insert_image(t_map *map)
{
	int	a;
	int	b;

	map->floor = mlx_xpm_file_to_image(map->mlx,
			"./files/floor.xpm", &a, &b);
	map->coin_a = mlx_xpm_file_to_image(map->mlx,
			"./files/collect.xpm", &a, &b);
	map->exit_a = mlx_xpm_file_to_image(map->mlx,
			"./files/exit_a.xpm", &a, &b);
	map->exit_b = mlx_xpm_file_to_image(map->mlx,
			"./files/exit_b.xpm", &a, &b);
	map->wall = mlx_xpm_file_to_image(map->mlx,
			"./files/wall.xpm", &a, &b);
	map->player_l = mlx_xpm_file_to_image(map->mlx,
			"./files/player_L.xpm", &a, &b);
	map->player_d = mlx_xpm_file_to_image(map->mlx,
			"./files/player_D.xpm", &a, &b);
	map->player_r = mlx_xpm_file_to_image(map->mlx,
			"./files/player_R.xpm", &a, &b);
	map->player_u = mlx_xpm_file_to_image(map->mlx,
			"./files/player_U.xpm", &a, &b);
}

void	ft_new_wind(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		exit(1);
	map->win = mlx_new_window(map->mlx, map->x * 64,
			map->y * 64, "so_long");
	insert_image(map);
	ft_draw(map);
	mlx_key_hook(map->win, on_click, map);
	mlx_loop(map->mlx);
}
