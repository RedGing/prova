/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_draw2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:53:58 by sum               #+#    #+#             */
/*   Updated: 2023/02/02 15:54:04 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_stay_img(int *last_img, t_game *game)
{
	static int	i;

	if (game->player->direction == LEFT)
	{
		if (*last_img != 1)
			i = 17;
		else if (i > 16 && i < 20)
			i++;
		else
			i = 17;
	}
	else
	{
		if (*last_img != 1)
			i = 0;
		else if (i > -1 && i < 3)
			i++;
		else
			i = 0;
	}
	*last_img = 1;
	return (i);
}

int	player_walk_img(int *last_img, t_game *game)
{
	static int	i;

	if (game->player->direction == LEFT)
	{
		if (*last_img != 2)
			i = 21;
		else if (i > 20 && i < 26)
			i++;
		else
			i = 21;
	}
	else
	{
		if (*last_img != 2)
			i = 4;
		else if (i > 3 && i < 10)
			i++;
		else
			i = 4;
	}
	*last_img = 2;
	return (i);
}
