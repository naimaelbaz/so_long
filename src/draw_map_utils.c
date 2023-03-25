/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:25:44 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/22 11:45:31 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_loop(t_map *m, t_var *v)
{
	if (m->data[v->i][v->j] == '0')
		mlx_put_image_to_window(m->mlx, m->win, m->floor, v->x, v->y);
	else if (m->data[v->i][v->j] == '1')
		mlx_put_image_to_window(m->mlx, m->win, m->wall, v->x, v->y);
	else if (m->data[v->i][v->j] == 'E')
		mlx_put_image_to_window(m->mlx, m->win, m->ex, v->x, v->y);
	else if (m->data[v->i][v->j] == 'P')
		mlx_put_image_to_window(m->mlx, m->win, m->pl, v->x, v->y);
	else if (m->data[v->i][v->j] == 'C')
		mlx_put_image_to_window(m->mlx, m->win, m->coin_a, v->x, v->y);
}

void	move_left(t_map	*map)
{
	map->data[map->plyer_y][map->plyer_x - 1] = 'P';
	map->data[map->plyer_y][map->plyer_x] = '0';
	mlx_clear_window(map->mlx, map->win);
	ft_draw(map);
}

void	move_right(t_map	*map)
{
	map->data[map->plyer_y][map->plyer_x + 1] = 'P';
	map->data[map->plyer_y][map->plyer_x] = '0';
	mlx_clear_window(map->mlx, map->win);
	ft_draw(map);
}

void	move_up(t_map	*map)
{
	map->data[map->plyer_y - 1][map->plyer_x] = 'P';
	map->data[map->plyer_y][map->plyer_x] = '0';
	mlx_clear_window(map->mlx, map->win);
	ft_draw(map);
}

void	move_down(t_map	*map)
{
	map->data[map->plyer_y + 1][map->plyer_x] = 'P';
	map->data[map->plyer_y][map->plyer_x] = '0';
	mlx_clear_window(map->mlx, map->win);
	ft_draw(map);
}
