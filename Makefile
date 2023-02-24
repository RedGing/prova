# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sum <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 17:54:27 by sum               #+#    #+#              #
#    Updated: 2023/02/07 17:54:32 by sum              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long

LIBFT = libft/libft.a
MINILIBX = minilibx-linux/libmlx.a

FLAGS = -no-pie -Wall -Werror -Wextra -g
LINKS = -lm -lX11 -lXext

SRC := main.c \
	hook.c \
	game_init.c \
	map_read.c \
	map_check.c \
	map_render.c \
	sprite_init.c \
	coin_init.c \
	exit_init.c \
	player_act.c \
	player_init.c \
	player_draw.c \
	player_draw2.c \
	player_status.c \
	image.c
	

all: $(NAME)

$(NAME): libcomp comp


libcomp:
		@make -C libft
	
comp:
	gcc $(FLAGS) $(SRC) $(MINILIBX) $(LIBFT) $(LINKS) -o $(NAME)
	
            
libclean:
		@make clean -C libft
		
clean:		libclean

libfclean:
		@make fclean -C libft

fclean:   	clean libfclean
		rm -rf $(NAME)
		
re: clean all

.PHONY: all re clean fclean bonus maps

.SILENT:
