# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 12:38:33 by nel-baz           #+#    #+#              #
#    Updated: 2023/03/21 14:14:05 by nel-baz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_B = so_long_bonus

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = 	gnl/get_next_line_utils.c \
		gnl/get_next_line.c\
		src/alloc_map.c\
		src/check_charactrs.c\
		src/check_map.c\
		src/draw_map.c\
		src/draw_map_utils.c\
		src/flood_fill.c\
		src/main.c\
		src/moves.c\
		src/moves_utils.c\
		src/so_long_utils.c\

SRCS_BONUS = 	gnl/get_next_line_utils.c\
				gnl/get_next_line.c\
				bonus/alloc_map_bonus.c\
				bonus/check_charactrs_bonus.c\
				bonus/check_map_bonus.c\
				bonus/draw_map_bonus.c\
				bonus/draw_map_utils_bonus.c\
				bonus/flood_fill_bonus.c\
				bonus/main_bonus.c\
				bonus/moves_bonus.c\
				bonus/moves_utils_bonus.c\
				bonus/so_long_utils_bonus.c\
				bonus/animtion_enemy.c\
				bonus/ft_itoa.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

src/%.o: src/%.c src/so_long.h ft_printf/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

gnl/%.o: gnl/%.c gnl/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

 bonus/%.o: bonus/%.c bonus/so_long_bonus.h ft_printf/ft_printf.h
	 $(CC) $(CFLAGS) -c $< -o $@

all : ft_printf $(NAME)

ft_printf :
	make -C ft_printf  all	

$(NAME):  $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) ./ft_printf/libftprintf.a -o $(NAME) -lmlx -framework OpenGL -framework AppKit

$(NAME_B):  $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) ./ft_printf/libftprintf.a -o $(NAME_B) -lmlx -framework OpenGL -framework AppKit
	
bonus : ft_printf $(NAME_B)

clean:	
	rm -rf $(OBJS) $(OBJS_BONUS)
	make -C ft_printf/ clean

fclean:	clean
	rm -rf $(NAME) $(NAME_B)
	make -C ft_printf/ fclean
		
re : fclean all

.PHONY : all fclean clean re ft_printf
