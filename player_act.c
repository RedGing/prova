/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_act.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:02:04 by sum               #+#    #+#             */
/*   Updated: 2023/01/25 16:02:05 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_actcode(int keycode)
{
	int	action;

	action = 0;
	if (keycode == A || keycode == ARROW_LEFT)
		action = 1;
	else if (keycode == S || keycode == ARROW_DOWN)
		action = 2;
	else if (keycode == D || keycode == ARROW_RIGHT)
		action = 3;
	else if (keycode == W || keycode == ARROW_UP)
		action = 4;
	return (action);
}

void	player_act(int keycode, t_game *game)
{
	t_player	*p;

	p = game->player;
	if (p->ac[0] == 0 || p->ac[0] == player_actcode(keycode))
		p->ac[0] = player_actcode(keycode);
	else if (p->ac[1] == 0 || p->ac[1] == player_actcode(keycode))
		p->ac[1] = player_actcode(keycode);
	if (p->ac[0] == 1)
		p->direction = LEFT;
	if (p->ac[0] == 3)
		p->direction = RIGHT;
}

void	player_disact(int keycode, t_game *game)
{
	t_player	*p;

	p = game->player;
	if (p->ac[0] == player_actcode(keycode))
		p->ac[0] = 0;
	if (p->ac[1] == player_actcode(keycode))
		p->ac[1] = 0;
	if (p->ac[0] == 0 && p->ac[1] != 0)
	{
		p->ac[0] = p->ac[1];
		p->ac[1] = 0;
	}
}
