/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:50:07 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/12 02:29:39 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>


typedef struct so_long
{
	int		x;
	int		y;
	char	**data;
	char	**data_tmp;
	int		plyer_x;
	int		plyer_y;
	int		num_c;
	int		num_e;
	int		num_p;
	int		exit;
	int		coins;
}t_map;


void	chack_map_name(char **argv);
void	exit_func(char *str);
void	insert_var(t_map *map);
void	ft_map_rectang(char *file, t_map *map);
void	ft_alloc_map(char *file, t_map *map);
void	free_map(char **str, int size);
void	check_map_walls(t_map *map);
void	check_map_components(t_map *map);
void	components_errors(t_map *map);
void	number_of_components(t_map *map);
void	position_player(t_map *map);
void	ft_alloc_map_tmp(t_map *map);
void	flood_fill(t_map *map, int pos_x, int pos_y);
void	number_of_coins(t_map *map, char **tmp);

#endif