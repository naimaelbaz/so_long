/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animtion_enemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:10:26 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/21 14:16:44 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	position_enemy(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->data[i])
	{
		j = 0;
		while (m->data[i][j])
		{
			if (m->data[i][j] == 'N')
				mlx_put_image_to_window(m->mlx, m->win,
					m->enemy_p, (j * 64), (i * 64));
			j++;
		}
		i++;
	}
}

void	draw_enemy(t_map *map, void *str)
{
	map->enemy_p = str;
	position_enemy(map);
}

int	ft_animation(t_map *map)
{
	static long	h;

	if (h == 1000)
		draw_enemy(map, map->enemy_a);
	if (h == 2000)
		draw_enemy(map, map->enemy_b);
	if (h == 3000)
		draw_enemy(map, map->enemy_c);
	if (h == 4000)
		draw_enemy(map, map->enemy_d);
	if (h == 5000)
		draw_enemy(map, map->enemy_e);
	if (h == 6000)
		draw_enemy(map, map->enemy_f);
	if (h == 7000)
		draw_enemy(map, map->enemy_j);
	if (h == 8000)
		draw_enemy(map, map->enemy_h);
	if (h == 9000)
	{
		draw_enemy(map, map->enemy_i);
		h = 0;
	}
	h++;
	return (0);
}
