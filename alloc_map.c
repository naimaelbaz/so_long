/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 03:45:41 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/09 01:27:57 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_strlen(char *s, char c)
{
	int	i;

	i = 0;
	if (s && c == '\0')
	{
		while (s[i])
			i++;
	}
	else if (s && c == '\n')
	{
		while (s[i] && s[i] != '\n')
			i++;
	}
	return (i);
}

void	chack_map_name(char **argv)
{
	int	i;

	i = my_strlen(argv[1], '\0') - 1;
	if (argv[1][i] != 'r' || argv[1][--i] != 'e'
		|| argv[1][--i] != 'b' || argv[1][--i] != '.' || !argv[1][--i])
		exit_func("problem withe the name of file");
}

void	insert_var(t_map *map)
{
	map->x = 0;
	map->y = 0;
	map->num_c = 0;
	map->num_e = 0;
	map->num_p = 0;
}

void	ft_map_rectang(char *file, t_map *map)
{
	char	*str;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		exit_func("problem in file");
	map->y++;

	i = my_strlen(str, '\n');
	free(str);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		map->x = my_strlen(str, '\n');
		if (i != map->x)
			exit_func("map is not rectangular!!");
		map->y++;
		free(str);
	}
	close(fd);
}

void	ft_alloc_map(char *file, t_map *map)
{
	int		fd;
	int		i;

	map->data = malloc(sizeof(char *) * (map->y + 1));
	if (!map->data)
		return ;
	i = 0;
	fd = open(file, O_RDONLY);
	while (i < map->y)
	{
		map->data[i] = get_next_line(fd);
		i++;
	}
	map->data[i] = NULL;
	close(fd);
}
