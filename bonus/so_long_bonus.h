/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:50:07 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/21 14:16:04 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
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
	int		num_n;
	int		exit;
	int		coins;
	int		enemy;
	void	*win;
	void	*mlx;
	void	*coin_a;
	void	*floor;
	void	*exit_a;
	void	*exit_b;
	void	*player_l;
	void	*player_d;
	void	*player_r;
	void	*player_u;
	void	*wall;
	void	*enemy_p;
	void	*enemy_a;
	void	*enemy_b;
	void	*enemy_c;
	void	*enemy_d;
	void	*enemy_e;
	void	*enemy_f;
	void	*enemy_j;
	void	*enemy_h;
	void	*enemy_i;
	void	*enemy_k;
	void	*fil;
	void	*ex;
	void	*pl;
	int		moves;
	int		en;
	int		enemy_x;
	int		enemy_y;
}			t_map;

typedef struct so_long_var
{
	int		x;
	int		y;
	int		i;
	int		j;
}			t_var;

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
void	valid_path(t_map *map);
int		my_strlen(char *s, char c);
char	*my_strdup(char *s1);
void	ft_new_wind(t_map *map);
void	ft_draw_loop(t_map *m, t_var *v);
void	move_3(t_map *map);
void	move_2(t_map *map);
void	move_1(t_map *map);
void	move_0(t_map *map);
void	move_player_left(t_map *map);
void	move_player_right(t_map *map);
void	move_player_up(t_map *map);
void	move_player_down(t_map *map);
void	move_left(t_map *map);
void	move_right(t_map *map);
void	move_up(t_map *map);
void	move_down(t_map *map);
void	ft_draw(t_map *m);
void	number_of_enemy(t_map *map, char **tmp);
char	*ft_itoa(int n);
int		ft_animation(t_map *map);
int		on_click(int keycode, t_map *map);
void	insert_image(t_map *map);

#endif