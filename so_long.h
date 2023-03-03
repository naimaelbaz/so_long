/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:50:07 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/03 03:35:39 by nel-baz          ###   ########.fr       */
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
}t_map;


void	chack_map_name(char **argv);
void	insert_var(t_map *map);
void	ft_map_rectang(char *file, t_map *map);
void	ft_alloc_map(char *file, t_map *map);
#endif