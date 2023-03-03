/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:28:48 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/03 03:36:07 by nel-baz          ###   ########.fr       */
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
		ft_printf("Error\n");
}

void	insert_var(t_map *map)
{
	map->x = 0;
	map->y = 0;
}

void	ft_map_rectang(char *file, t_map *map)
{
	char	*str;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		exit(1);
	i = my_strlen(str, '\n');
	free(str);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		map->x = my_strlen(str, '\n');
		if (i != map->x)
		{
			ft_printf("map is not rectangular!!");
			exit(1);
		}
		map->y++;
		free(str);
	}
}

void	ft_alloc_map(char *file, t_map *map)
{
	int		fd;
	char	*str;

	map->data = malloc(sizeof(char))
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		exit(1);
	
}
