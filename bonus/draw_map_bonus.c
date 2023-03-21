/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:50:40 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/21 14:15:13 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_draw(t_map *m)
{
	t_var		v;
	char		*str;

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
	str = ft_itoa(m->moves);
	mlx_put_image_to_window(m->mlx, m->win, m->fil, 0, 0);
	mlx_string_put(m->mlx, m->win, 64, 22, 0x0A1FD1, str);
	free(str);
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

void	*xpm_to_img(t_map *map, char *tmp)
{
	void	*mlx;
	int		a;
	int		b;

	mlx = mlx_xpm_file_to_image(map->mlx, tmp, &a, &b);
	if (!mlx)
		exit_func("\033[0;31min mlx files");
	return (mlx);
}

void	insert_image(t_map *map)
{
	map->floor = xpm_to_img(map, "./files/floor.xpm");
	map->coin_a = xpm_to_img(map, "./files/collect.xpm");
	map->exit_a = xpm_to_img(map, "./files/exit_a.xpm");
	map->exit_b = xpm_to_img(map, "./files/exit_b.xpm");
	map->wall = xpm_to_img(map, "./files/wall.xpm");
	map->player_l = xpm_to_img(map, "./files/player_L.xpm");
	map->player_d = xpm_to_img(map, "./files/player_D.xpm");
	map->player_r = xpm_to_img(map, "./files/player_R.xpm");
	map->player_u = xpm_to_img(map, "./files/player_U.xpm");
	map->enemy_a = xpm_to_img(map, "./files/1.xpm");
	map->enemy_b = xpm_to_img(map, "./files/2.xpm");
	map->enemy_c = xpm_to_img(map, "./files/3.xpm");
	map->enemy_d = xpm_to_img(map, "./files/4.xpm");
	map->enemy_e = xpm_to_img(map, "./files/5.xpm");
	map->enemy_f = xpm_to_img(map, "./files/6.xpm");
	map->enemy_j = xpm_to_img(map, "./files/7.xpm");
	map->enemy_h = xpm_to_img(map, "./files/8.xpm");
	map->enemy_i = xpm_to_img(map, "./files/9.xpm");
	map->fil = xpm_to_img(map, "./files/set.xpm");
	map->enemy_p = map->enemy_a;
	map->pl = map->player_d;
	map->ex = map->exit_a;
}
