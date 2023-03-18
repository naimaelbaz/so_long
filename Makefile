# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 12:38:33 by nel-baz           #+#    #+#              #
#    Updated: 2023/03/18 19:18:42 by nel-baz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = 	gnl/get_next_line_utils.c \
		gnl/get_next_line.c\
		./alloc_map.c\
		./check_charactrs.c\
		./check_map.c\
		./draw_map.c\
		./draw_map_utils.c\
		./flood_fill.c\
		./main.c\
		./moves.c\
		./moves_utils.c\
		./so_long_utils.c\
		

# SRCS_BONUS =

OBJS = $(SRCS:.c=.o)

# OBJS_BONUS = $(SRCS_BONUS:.c=.o)

./%.o: ./%.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

gnl/%.o: gnl/%.c gnl/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

#  bonus/%.o: bonus/%.c bonus/push_swap_bonus.h ../libft/libft.h
# 	 $(CC) $(CFLAGS) -c $< -o $@

all : ft_printf $(NAME)

ft_printf :
	make -C ft_printf  all	

$(NAME):  $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) ./ft_printf/libftprintf.a -o $(NAME) -lmlx -framework OpenGL -framework AppKit

# $(NAME_B):  $(OBJS_BONUS)
# 	$(CC) $(CFLAGS) $(OBJS_BONUS) ./libft/libft.a -o $(NAME_B)
	
# bonus : all $(NAME_B)

clean:	
	rm -rf $(OBJS)
	make -C ft_printf/ clean

fclean:	clean
	rm -rf $(NAME)
	make -C ft_printf/ fclean
		
re : fclean all

.PHONY : all fclean clean re ft_printf
