/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animtion_enemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:10:26 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/25 21:54:00 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_position_enemy(t_map *m)
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
	get_position_enemy(map);
}

int	ft_animation(t_map *map)
{
	static long	h;

	if (h == 1000)
	{
		if (map->eny == 0)
			draw_enemy(map, map->enemy_a);
		else
			draw_enemy(map, map->enemy_ar);
	}
	if (h == 2000)
	{
		if (map->eny == 0)
			draw_enemy(map, map->enemy_b);
		else
			draw_enemy(map, map->enemy_br);
	}
	if (h == 3000)
	{
		if (map->eny == 0)
			draw_enemy(map, map->enemy_c);
		else
			draw_enemy(map, map->enemy_cr);
	}
	if (h == 4000)
	{
		if (map->eny == 0)
			draw_enemy(map, map->enemy_d);
		else
			draw_enemy(map, map->enemy_dr);
	}
	if (h == 5000)
	{
		if (map->eny == 0)
			draw_enemy(map, map->enemy_e);
		else
			draw_enemy(map, map->enemy_er);
	}
	if (h == 6000)
	{
		if (map->eny == 0)
			draw_enemy(map, map->enemy_f);
		else
			draw_enemy(map, map->enemy_fr);
	}
	if (h == 7000)
	{
		if (map->eny == 0)
			draw_enemy(map, map->enemy_j);
		else
			draw_enemy(map, map->enemy_jr);
	}
	if (h == 8000)
	{
		if (map->eny == 0)
			draw_enemy(map, map->enemy_h);
		else
			draw_enemy(map, map->enemy_hr);	
	}
	if (h == 8010)
	{
		position_enemy(map);
		h = 0;
	}
	h++;
	return (0);
}
