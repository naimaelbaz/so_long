/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 03:46:10 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/09 01:28:41 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_func(char *str)
{
	ft_printf("Error, %s\n", str);
	exit(1);
}

void	check_map_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->y)
	{
		if (map->data[i][0] != '1' || map->data[i][map->x - 1] != '1')
		{
			exit_func("map is not closed🙂");
		}
		i++;
	}
	i = 0;
	while (i < map->x)
	{
		if (map->data[0][i] != '1' || map->data[map->y - 1][i] != '1')
			exit_func("map is not closed🙂");
		i++;
	}
}

void	check_map_components(t_map *map)
{
	int	i;
	int	j;

	j = 1;
	while (j < map->y)
	{
		i = 0;
		while (i < map->x)
		{
			if (map->data[j][i] != 'E' && map->data[j][i] != '0'
			&& map->data[j][i] != '1' && map->data[j][i] != 'P'
			&& map->data[j][i] != 'C')
				exit_func("invalid character");
			i++;
		}
		j++;
	}
}

void	free_map(char **str, int size)
{
	int	i;

	i = 0;
	while (i <= size)
		free(str[i++]);
	free(str);
}
