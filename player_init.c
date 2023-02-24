/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:17:23 by sum               #+#    #+#             */
/*   Updated: 2023/01/25 15:17:24 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move_count(t_game *game)
{
	t_player	*p;

	p = game->player;
	if (p->x + 2 != p->a[0] || p->y != p->a[1])
	{
		game->move++;
		printf("Movement: %d\n", game->move);
	}
}

void	player_move_x(t_game *game)
{
	t_player	*p;
	char		**m;

	p = game->player;
	m = game->map;
	if (p->ac[0] == 1)
	{
		if (m[p->a[1] / 32][(p->a[0] - 2) / 32] != WALL &&
		m[p->c[1] / 32][(p->c[0] - 1) / 32] != WALL)
			p->x -= 2;
	}
	else if (p->ac[0] == 3)
	{
		if (m[p->b[1] / 32][(p->b[0] + 2) / 32] != WALL &&
		m[p->d[1] / 32][(p->d[0] + 2) / 32] != WALL)
			p->x += 2;
	}
}

void	player_move_y(t_game *game)
{
	t_player	*p;
	char		**m;

	p = game->player;
	m = game->map;
	if (p->ac[0] == 2)
	{
		if (m[(p->c[1] + 2) / 32][p->c[0] / 32] != WALL &&
		m[(p->d[1] + 2) / 32][p->d[0] / 32] != WALL)
			p->y += 2;
	}
	else if (p->ac[0] == 4)
	{
		if (m[(p->a[1] - 2) / 32][p->a[0] / 32] != WALL &&
		m[(p->b[1] - 2) / 32][p->b[0] / 32] != WALL)
			p->y -= 2;
	}
}

void	player_position(t_game *game)
{
	t_player	*p;

	p = game->player;
	p->a[0] = p->x + 2;
	p->a[1] = p->y;
	p->b[0] = p->x + 14;
	p->b[1] = p->y;
	p->c[0] = p->x + 2;
	p->c[1] = p->y + 19;
	p->d[0] = p->x + 14;
	p->d[1] = p->y + 19;
}

void	player_init(t_game *game)
{
	player_position(game);
	player_move_x(game);
	player_move_y(game);
	player_draw(game);
	player_move_count(game);
	player_status(game);
}
