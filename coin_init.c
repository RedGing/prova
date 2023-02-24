/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:42:10 by sum               #+#    #+#             */
/*   Updated: 2023/01/25 13:42:12 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coin_draw(t_game *game, int i, int j, char *buffer, t_image *map)
{	
	static int	num_img;
	static int	img_inter;

	if (img_inter > game->c * 5)
	{
		img_inter = 0;
		if (num_img < 3)
			num_img++;
		else
			num_img = 0;
	}
	else
		img_inter++;
	construct_image(buffer, i * 32, j * 32, *map, game->sprites[num_img]);
}

static void	coin_load(t_game *game, char *buffer, t_image *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->maph)
	{
		j = 0;
		while (j < game->mapw)
		{
			if (game->map[i][j] == COIN)
				coin_draw(game, i, j, buffer, map);
			j++;
		}
		i++;
	}
}

static void	coin_eaten(t_game *game)
{
	t_player	*p;

	p = game->player;
	if (game->map[p->a[1] / 32][p->a[0] / 32] == COIN)
	{
		game->map[p->a[1] / 32][p->a[0] / 32] = FLOOR;
		game->c--;
	}
	else if (game->map[p->b[1] / 32][p->b[0] / 32] == COIN)
	{
		game->map[p->b[1] / 32][p->b[0] / 32] = FLOOR;
		game->c--;
	}	
	else if (game->map[p->c[1] / 32][p->c[0] / 32] == COIN)
	{
		game->map[p->c[1] / 32][p->c[0] / 32] = FLOOR;
		game->c--;
	}
	else if (game->map[p->d[1] / 32][p->d[0] / 32] == COIN)
	{
		game->map[p->d[1] / 32][p->d[0] / 32] = FLOOR;
		game->c--;
	}
}	

void	coin_init(t_game *game, char *buffer, t_image *map)
{
	coin_load(game, buffer, map);
	coin_eaten(game);
}
