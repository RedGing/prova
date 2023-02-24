/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:22:47 by sum               #+#    #+#             */
/*   Updated: 2023/02/02 14:22:48 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	player_img(int *last_img, t_game *game)
{
	if (game->player->ac[0] == 1 || game->player->ac[0] == 3)
		return (player_walk_img(last_img, game));
	else if (game->player->ac[0] == 2 || game->player->ac[0] == 4)
		return (player_walk_img(last_img, game));
	else
		return (player_stay_img(last_img, game));
}

int	*player_anim(t_game *game)
{
	static int	num;
	static int	last_img;
	static int	img_inter;

	if (img_inter > 5)
	{
		img_inter = 0;
		num = player_img(&last_img, game);
	}
	else
		img_inter++;
	return (game->player->img[num]);
}

void	player_draw(t_game *game)
{
	t_player	*p;

	p = game->player;
	mlx_put_image_to_window(game->mlx, game->win, \
			player_anim(game), p->x, p->y);
}
