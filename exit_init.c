/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:19:14 by sum               #+#    #+#             */
/*   Updated: 2023/02/09 16:19:15 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	exit_finish(t_game *game)
{
	t_player	*p;

	p = game->player;
	if (game->map[p->a[1] / 32][p->a[0] / 32] == EXIT ||
		game->map[p->b[1] / 32][p->b[0] / 32] == EXIT ||
		game->map[p->c[1] / 32][p->c[0] / 32] == EXIT ||
		game->map[p->d[1] / 32][p->d[0] / 32] == EXIT)
	{
		if (game->c == 0)
		{
			exit_error("SUCCESS! CONGRATULATION!");
			mlx_destroy_window(game->mlx, game->win);
		}
		else
			printf("You should eat all the coins!");
	}
}	

void	exit_draw(t_game *game, int i, int j, char *buffer, t_image *map)
{
	static int	num_img;
	static int	img_inter;


	if (img_inter == 10)
	{
		img_inter = 0;
		if (game-> c != 0)
		{
			if (num_img < 4)
				num_img++;
			else
				num_img = 0;
		}
		else
		{
			if (num_img == 3 || num_img == 6)
				num_img = 6;
			if (num_img == 5)
				num_img = 0;
			else if (num_img > 3 && num_img < 5)
				num_img++;				
			else if (num_img < 3)
				num_img++;
		}	
	}
	else
		img_inter++;
	construct_image(buffer, i * 32, j * 32, *map, game->sprites[num_img]);
}

static void	exit_load(t_game *game, char *buffer, t_image *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->maph)
	{
		j = 0;
		while (j < game->mapw)
		{
			if (game->map[i][j] == EXIT)
				exit_draw(game, i, j, buffer, map);
			j++;
		}
		i++;
	}
}

void	exit_init(t_game *game, char *buffer, t_image *map)
{
	exit_load(game, buffer, map);
	exit_finish(game);
}
