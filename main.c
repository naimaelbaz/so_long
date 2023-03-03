/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:44:54 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/03 03:35:46 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void pop()
// {
// 	system("leaks so_long");
// }

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		chack_map_name(argv);
		insert_var(&map);
		ft_map_rectang(argv[1], &map);
		ft_alloc_map(argv[1], &map);
	}
	// atexit(pop);
	return (0);
}
