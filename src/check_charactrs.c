/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_charactrs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:36:27 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/21 10:21:54 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	number_of_components(t_map *map)
{
	int	i;
	int	j;

	j = 1;
	while (j < map->y)
	{
		i = 0;
		while (i < map->x)
		{
			if (map->data[j][i] == 'C')
				map->num_c++;
			if (map->data[j][i] == 'E')
				map->num_e++;
			if (map->data[j][i] == 'P')
				map->num_p++;
			i++;
		}
		j++;
	}
}

void	components_errors(t_map *map)
{
	if (map->data[map->y - 1][map->x] == '\n')
		exit_func("\033[0;31mmap is not rectangular🙂");
	if (map->num_p != 1)
		exit_func("\033[0;31mthe map must have one plyer🙂");
	if (map->num_e != 1)
		exit_func("\033[0;31mthe map must have one exit🙂");
	if (map->num_c == 0)
		exit_func("\033[0;31mthe map must have at least one collectible🙂");
}
