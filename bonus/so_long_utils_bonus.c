/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:57:08 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/20 19:02:58 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	insert_var(t_map *map)
{
	map->x = 0;
	map->y = 0;
	map->exit = 0;
	map->num_c = 0;
	map->num_e = 0;
	map->num_p = 0;
	map->num_n = 0;
	map->plyer_x = 0;
	map->plyer_y = 0;
	map->ex = 0;
	map->pl = 0;
	map->moves = 0;
	map->enemy = 0;
	map->enemy_x = 0;
	map->enemy_y = 0;
}

void	exit_func(char *str)
{
	ft_printf("\033[0;31mError, %s\n", str);
	exit(1);
}

void	free_map(char **str, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(str[i++]);
	free(str);
}

char	*my_strdup(char *s1)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	if (!s1)
		return (NULL);
	i = my_strlen(s1, '\0');
	str = malloc(i * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[j] != '\0')
	{
		str[j] = s1[j];
		j++;
	}
	return (str);
}
