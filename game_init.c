/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:34:50 by sum               #+#    #+#             */
/*   Updated: 2023/02/07 15:34:51 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game, int argc)
{
	if (argc != 2)
		exit_error("The map file is missing or wrong arguments.");
	game->mlx = mlx_init();
	game->maph = 0;
	game->mapw = 0;
	game->temp = 0;
	game->move = 0;
	game->c = 0;
	game->e = 0;
	game->p = 0;
	game->sprites = NULL;
	game->player = ft_calloc(sizeof(t_player), 1);
	game->coin = ft_calloc(sizeof(t_coin), 1);
	game->wall = ft_calloc(sizeof(t_image), 1);
	game->exit = ft_calloc(sizeof(t_exit), 1);
	game->floor = ft_calloc(sizeof(t_image), 1);
	game->flower2 = ft_calloc(sizeof(t_image), 1);
	game->flower = ft_calloc(sizeof(t_image), 1);
	game->water = ft_calloc(sizeof(t_image), 1);
	game->water_l = ft_calloc(sizeof(t_image), 1);
	game->water_m = ft_calloc(sizeof(t_image), 1);
	game->water_r = ft_calloc(sizeof(t_image), 1);
}
