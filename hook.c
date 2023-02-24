/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:33:43 by sum               #+#    #+#             */
/*   Updated: 2023/02/06 15:33:45 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	kill_hook(int keycode, t_game *game)
{
	if (keycode == 0)
		mlx_destroy_window(game->mlx, game->win);
	exit(0);
}	

int	keydown_hook(int keycode, t_game *game)
{
	player_act(keycode, game);
	return (0);
}

int	keyup_hook(int keycode, t_game *game)
{
	if (keycode != ESC)
		player_disact(keycode, game);
	else
		kill_hook(0, game);
	return (0);
}
